#pragma force_active on

#define ASM_ as##m

extern "C" const float lbl_73_rodata_0;

extern "C" ASM_ int fn_73_2AE0(int unused, float* out) {
    lis r5, lbl_73_rodata_0@ha
    li r3, 0x0
    lfs f0, lbl_73_rodata_0@l(r5)
    stfs f0, 0x0(r4)
    stfs f0, 0x4(r4)
    stfs f0, 0x8(r4)
    blr
}
