#include <types.h>
#pragma force_active on

struct SoGuardObj {
    u32 m0;
    s32 m4;
    s16 m8;
    s16 mA;
    ~SoGuardObj();
};

extern "C" void* __register_global_object(void* obj, void* dtor, void* chain);
extern "C" void fn_27_845D8(void*, int);

extern "C" s8 lbl_27_bss_12C8;
extern "C" SoGuardObj lbl_27_bss_12CC;
extern "C" u8 lbl_27_bss_EFC[12];

extern "C" void* fn_27_8401C() {
    if (!lbl_27_bss_12C8) {
        lbl_27_bss_12CC.m4 = -1;
        lbl_27_bss_12CC.m8 = 0;
        lbl_27_bss_12CC.mA = -1;
        __register_global_object(&lbl_27_bss_12CC, (void*)fn_27_845D8, lbl_27_bss_EFC);
        lbl_27_bss_12C8 = 1;
    }
    return &lbl_27_bss_12CC;
}
