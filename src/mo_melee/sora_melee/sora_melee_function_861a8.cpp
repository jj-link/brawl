#include <types.h>
#pragma force_active on

extern "C" {
    extern s8 lbl_27_bss_1920;
    extern u8 lbl_27_bss_1928[];
    extern const float lbl_27_rodata_B74;
    extern u8 lbl_27_bss_1034[];
    void __dt__25soCollisionAttackAbsoluteFv(void);
    void __register_global_object(void* obj, void* dtor, void* chain);
}

extern "C" void* fn_27_861A8(void)
{
    if (lbl_27_bss_1920 == 0) {
        float f = lbl_27_rodata_B74;
        u8* obj = lbl_27_bss_1928;
        *(float*)(obj + 0x24) = f;
        *(float*)(obj + 0x28) = f;
        *(float*)(obj + 0x2c) = f;
        *(u32*)(obj + 0x38) = *(u32*)(obj + 0x38) & ~31u;
        __register_global_object(obj, (void*)__dt__25soCollisionAttackAbsoluteFv, lbl_27_bss_1034);
        lbl_27_bss_1920 = 1;
    }
    return lbl_27_bss_1928;
}
