#pragma force_active on
typedef unsigned int u32;

u32 fn_803A98A8(void);

u32 fn_803BE008(void) {
    u32 x = fn_803A98A8();
    return (-x | x) >> 31;
}
