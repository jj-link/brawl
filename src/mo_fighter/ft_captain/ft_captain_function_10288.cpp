#include <it/it_manager.h>
#pragma force_active on

extern "C" {
BaseItem* fn_27_2A898C(itManager*, int);
extern unsigned long long lbl_100_bss_2C8;
}

#define D10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

namespace {
struct FakePad {
    char pad[0x3c];
};
struct FakeItem : FakePad {
    D10(a) D10(b) D10(c) D10(d) D10(e) D10(f) D10(g) D10(h) D10(i) D10(j) D10(k) D10(l) D10(m)
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void setVis(bool);
};

inline bool has(unsigned long long a, unsigned long long b) {
    return (a & b) != 0ULL;
}
}

extern "C" void fn_100_10288() {
    unsigned long long bits = lbl_100_bss_2C8;
    unsigned long long bit;
    unsigned int count;
    int i;
    itManager* manager = itManager::getInstance();
    count = static_cast<soArray<BaseItem*>&>(manager->m_itemArrayList).size();
    if (count >= 64) count = 64;
    bit = 1;
    for (i = 0; i < static_cast<int>(count); ++i) {
        FakeItem* item = reinterpret_cast<FakeItem*>(fn_27_2A898C(manager, i));
        if (has(bit, ~0ULL)) {
            item->setVis(has(bits, bit));
        }
        bit <<= 1;
    }
}
