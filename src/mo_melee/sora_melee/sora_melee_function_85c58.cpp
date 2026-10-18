#include <types.h>
#pragma force_active on

extern "C" {
void* __register_global_object(void* object, void* destructor, void* chain);
void fn_27_86D4C();
}

extern s8 lbl_27_bss_1700;
extern u8 lbl_27_bss_FE0[];
extern u8 lbl_27_bss_1708[];
extern const float lbl_27_rodata_B74;

struct SoraObj {
    u8 pad0[0x60];
    float f60;
    float f64;
    float f68;
    u8 pad1[8];
    u32 f74;
};

extern "C" void* fn_27_85C58() {
    if (!lbl_27_bss_1700) {
        SoraObj* o = (SoraObj*)lbl_27_bss_1708;
        float f = lbl_27_rodata_B74;
        o->f60 = f;
        o->f64 = f;
        o->f68 = f;
        o->f74 = o->f74 & ~31u;
        __register_global_object(lbl_27_bss_1708, (void*)fn_27_86D4C, lbl_27_bss_FE0);
        lbl_27_bss_1700 = 1;
    }
    return lbl_27_bss_1708;
}
