#include <it/it_manager.h>

extern "C" {
BaseItem* fn_27_2A898C(itManager*, int);
extern unsigned long long lbl_100_bss_2C8;
}

namespace {
// The original mask uses a signed 32-bit shift before widening to 64 bits.
inline unsigned long long itemBit(int index) {
    return static_cast<long long>(1 << index);
}
inline bool hasItemBit(unsigned long long bits, int index) {
    return (itemBit(index) & bits) != 0ULL;
}
inline unsigned long long removeItemBit(unsigned long long bits, int index) {
    if (index < 0 || static_cast<unsigned int>(index) <= 64) {
        return bits;
    }
    unsigned long long lower = static_cast<long long>((1 << index) - 1);
    return ((bits & (~lower << 1)) >> 1) | (bits & lower);
}
inline void saveVisibility() {
    itManager* manager = itManager::getInstance();
    int i;
    unsigned int count = manager->m_itemArrayList.size();
    if (count >= 64) count = 64;
    unsigned long long visibility = 0;
    for (i = 0; i < static_cast<int>(count); ++i) {
        if (fn_27_2A898C(manager, i)->getVisibilityWhole()) {
            visibility |= itemBit(i);
        }
    }
    lbl_100_bss_2C8 = visibility;
}
inline void removeHeldItems() {
    itManager* manager = itManager::getInstance();
    for (int i = manager->m_itemArrayList.size() - 1; i >= 0; --i) {
        BaseItem* item = fn_27_2A898C(manager, i);
        if (item->isHaved()) {
            item->remove();
            lbl_100_bss_2C8 = removeItemBit(lbl_100_bss_2C8, i);
        }
    }
}
inline void hideItems(unsigned long long bits) {
    itManager* manager = itManager::getInstance();
    int i;
    unsigned int count = manager->m_itemArrayList.size();
    if (count >= 64) count = 64;
    for (i = 0; i < static_cast<int>(count); ++i) {
        if (hasItemBit(bits, i)) {
            fn_27_2A898C(manager, i)->setVisibilityWholeForce(0);
        }
    }
}
}

extern "C" void fn_100_10070() {
    saveVisibility();
    removeHeldItems();
    hideItems(~0ULL);
}
