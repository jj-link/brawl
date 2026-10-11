#include <types.h>

struct LuigiEnergyVector {
    float x, y;
};

struct LuigiEnergyVectorPrefix {
    u8 prefix[8];
    LuigiEnergyVector speed;
    LuigiEnergyVector vector10;
    LuigiEnergyVector vector18;
    LuigiEnergyVector vector20;
    LuigiEnergyVector vector28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" {
extern const float lbl_99_rodata_8;
extern const float lbl_99_rodata_C;
LuigiEnergyVector* fn_99_AA80(LuigiEnergyVector*, const LuigiEnergyVector*);
}

extern "C" void fn_99_AA44(void*) {
}

extern "C" void fn_99_AA48(LuigiEnergyVectorPrefix* energy) {
    LuigiEnergyVector zero = {lbl_99_rodata_8, lbl_99_rodata_8};
    fn_99_AA80(&energy->speed, &zero);
}

extern "C" LuigiEnergyVector* fn_99_AA80(LuigiEnergyVector* destination,
                                      const LuigiEnergyVector* source) {
    destination->x = source->x;
    destination->y = source->y;
    return destination;
}

extern "C" void fn_99_AA94(LuigiEnergyVectorPrefix* energy) {
    LuigiEnergyVector zero = {lbl_99_rodata_8, lbl_99_rodata_8};
    fn_99_AA80(&energy->speed,
        fn_99_AA80(&energy->vector10, fn_99_AA80(&energy->vector20, &zero)));
    LuigiEnergyVector limits = {lbl_99_rodata_C, lbl_99_rodata_C};
    fn_99_AA80(&energy->vector18, fn_99_AA80(&energy->vector28, &limits));
    energy->flag31 = 0;
    energy->flag30 = 0;
    energy->flag32 = 1;
}
