#pragma force_active on
extern "C" const float lbl_67_rodata_0;

extern "C" void fn_67_1B80(char *self)
{
    char *p = *(char **)(self + 0x9c);
    if (p == 0) {
        return;
    }
    *(float *)(self + 0x218) = lbl_67_rodata_0;
    *(float *)(self + 0x21c) = lbl_67_rodata_0;
    *(float *)(self + 0x220) = lbl_67_rodata_0;
    *(float *)(self + 0x224) = lbl_67_rodata_0;
    *(float *)(self + 0x228) = lbl_67_rodata_0;
    *(float *)(self + 0x22c) = lbl_67_rodata_0;
    *(float *)(self + 0x230) = *(float *)(p + 0x70);
    *(float *)(self + 0x234) = lbl_67_rodata_0;
    *(unsigned char *)(self + 0x238) = 2;
    *(float *)(self + 0x23c) = lbl_67_rodata_0;
    *(unsigned char *)(self + 0x240) = 0;
}
