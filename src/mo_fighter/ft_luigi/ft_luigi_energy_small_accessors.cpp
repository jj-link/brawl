#include <mt/mt_vector.h>

struct LuigiEnergyFlagPrefix {
    u8 prefix[0x31];
    u8 flag31;
};

struct LuigiDispatchSpeed {
    float x, y;
};

struct LuigiEnergySpeedPrefix {
    u8 prefix[8];
    LuigiDispatchSpeed speed;
};

extern "C" const float lbl_99_rodata_8;

extern "C" void fn_99_AB2C(LuigiEnergyFlagPrefix* energy) {
    energy->flag31 = 0;
}

extern "C" void fn_99_AB38(LuigiEnergyFlagPrefix* energy) {
    energy->flag31 = 1;
}

extern "C" Vec3f fn_99_AB44(const LuigiEnergySpeedPrefix*) {
    return Vec3f(lbl_99_rodata_8, lbl_99_rodata_8, lbl_99_rodata_8);
}

extern "C" LuigiDispatchSpeed fn_99_AB5C(const LuigiEnergySpeedPrefix* energy) {
    return energy->speed;
}
