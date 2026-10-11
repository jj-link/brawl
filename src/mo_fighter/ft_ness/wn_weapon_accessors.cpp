#include <wn/weapon.h>

// Shared weapon callbacks referenced by the Ness module's original virtual tables.
// Only the documented field offsets are needed; the full weapon layout stays opaque.
struct NessWeaponFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

static inline NessWeaponFlags* weaponFlags(void* object) {
    return reinterpret_cast<NessWeaponFlags*>(static_cast<unsigned char*>(object) + 0xA4);
}

extern "C" unsigned int fn_101_15C78(void* object) {
    return *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(object) + 0xC0);
}

extern "C" unsigned int fn_101_15C80(void* object) {
    return *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(object) + 0x28);
}

extern "C" bool fn_101_15C88(void* object) {
    return static_cast<Weapon*>(object)->isActive();
}

extern "C" bool fn_101_15C98(void* object) {
    return weaponFlags(object)->selected != 0;
}

extern "C" void fn_101_15CAC(void* object, bool selected) {
    weaponFlags(object)->selected = selected;
}

extern "C" bool fn_101_15CBC(void*, char eventKind) {
    char observedKind = 12;
    return eventKind == observedKind;
}

extern "C" bool fn_101_15CD8(void*) {
    return false;
}

extern "C" bool fn_101_15CE0(void*) {
    return true;
}
