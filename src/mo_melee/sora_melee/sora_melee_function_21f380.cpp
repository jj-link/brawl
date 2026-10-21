#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1F1F58(s32);
extern "C" s32 fn_27_1F2D0C(s32);
extern "C" void* fn_27_1F218C(s32);

struct Rodata3290 {
    char pad0[0x40];
    f32 f40;
    char pad44[0x10];
    f32 f54;
    char pad58[0x10];
    f32 f68;
};
extern Rodata3290 lbl_27_rodata_3290;

extern "C" f32 fn_27_21F380(s32 arg0) {
    Rodata3290* r = &lbl_27_rodata_3290;
    char* state = (char*)fn_27_1F1F58(arg0);
    if (fn_27_1F2D0C(arg0) != 0) {
        return (r->f40 + r->f54 * *(f32*)(state + 0x68)) * (*(f32*)((char*)fn_27_1F218C(*(s32*)(state + 0xAC)) + 0x1C) - r->f68);
    }
    return (r->f40 + r->f54 * *(f32*)(state + 0x68)) * (*(f32*)((char*)fn_27_1F218C(0) + 0x1C) - r->f68);
}
