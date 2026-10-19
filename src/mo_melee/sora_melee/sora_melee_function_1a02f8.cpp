#include <types.h>
#pragma force_active on

struct Fn27Obj {
    f32 m0;
    f32 m4;
    f32 m8;
    u32 mC;
};

extern "C" {
extern const f32 lbl_27_rodata_2708;
extern const f32 lbl_27_rodata_270C;

void fn_27_1A02F8(Fn27Obj* obj) {
    obj->mC = (obj->mC | 0xF8000000);
    obj->m0 = lbl_27_rodata_2708;
    obj->m4 = lbl_27_rodata_2708;
    obj->m8 = lbl_27_rodata_270C;
    obj->mC = obj->mC;
    ((u8*)&obj->mC)[1] = 0;
}
}
