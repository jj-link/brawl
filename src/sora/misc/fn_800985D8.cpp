#pragma force_active on
extern "C" {
extern float lbl_80532550[4];
extern const float lbl_805A1D40;
extern const float lbl_805A1D44;
extern const float lbl_805A1D48;
extern const float lbl_805A1D4C;
extern const float lbl_805A1D50;
}

extern "C" void fn_800985D8(char *p)
{
    float arr[4] __attribute__((aligned(16)));
    *(int *)(p + 0x0) = -1;
    *(short *)(p + 0x4) = -1;
    *(short *)(p + 0x6) = -1;
    *(short *)(p + 0x8) = -1;
    *(short *)(p + 0xA) = -1;
    *(float *)(p + 0x10) = lbl_805A1D40;
    *(float *)(p + 0x14) = lbl_805A1D44;
    *(float *)(p + 0x18) = lbl_805A1D44;
    *(float *)(p + 0x1C) = lbl_805A1D44;
    *(float *)(p + 0x20) = lbl_805A1D40;
    *(float *)(p + 0x24) = lbl_805A1D48;
    *(float *)(p + 0x28) = lbl_805A1D48;
    *(float *)(p + 0x2C) = lbl_805A1D48;
    arr[0] = lbl_805A1D40;
    arr[1] = lbl_805A1D44;
    arr[2] = lbl_805A1D44;
    arr[3] = lbl_805A1D44;
    *(float *)(p + 0x30) = lbl_80532550[0];
    *(float *)(p + 0x34) = lbl_80532550[1];
    *(float *)(p + 0x38) = lbl_80532550[2];
    *(float *)(p + 0x3C) = lbl_80532550[3];
    *(float *)(p + 0x40) = lbl_80532550[0];
    *(float *)(p + 0x44) = lbl_80532550[1];
    *(float *)(p + 0x48) = lbl_80532550[2];
    *(float *)(p + 0x4C) = lbl_80532550[3];
    *(float *)(p + 0x50) = lbl_805A1D4C;
    *(float *)(p + 0x54) = lbl_805A1D4C;
    *(float *)(p + 0x58) = lbl_805A1D50;
    *(float *)(p + 0x5C) = lbl_805A1D50;
}
