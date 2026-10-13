#include <wn/weapon.h>

namespace {
inline Weapon& articleAt(char* pool, int index) {
    // The nineteen weapon slots begin after the pool header.
    return *reinterpret_cast<Weapon*>(pool + 0x54 + index * 0x27c4);
}
}

extern "C" Weapon& fn_117_C194(void* pool, int index) {
    char* storage = static_cast<char*>(pool);
    if (index == 18) return articleAt(storage, 18);
    if (index == 17) return articleAt(storage, 17);
    if (index == 16) return articleAt(storage, 16);
    if (index == 15) return articleAt(storage, 15);
    if (index == 14) return articleAt(storage, 14);
    if (index == 13) return articleAt(storage, 13);
    if (index == 12) return articleAt(storage, 12);
    if (index == 11) return articleAt(storage, 11);
    if (index == 10) return articleAt(storage, 10);
    if (index == 9) return articleAt(storage, 9);
    if (index == 8) return articleAt(storage, 8);
    if (index == 7) return articleAt(storage, 7);
    if (index == 6) return articleAt(storage, 6);
    if (index == 5) return articleAt(storage, 5);
    if (index == 4) return articleAt(storage, 4);
    if (index == 3) return articleAt(storage, 3);
    if (index == 2) return articleAt(storage, 2);
    if (index == 1) return articleAt(storage, 1);
    if (index == 0) return articleAt(storage, 0);
    return *static_cast<Weapon*>(0);
}
