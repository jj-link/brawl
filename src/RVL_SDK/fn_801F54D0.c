#pragma force_active on
typedef unsigned int u32;

extern float lbl_805A38E0;
extern float lbl_805A38D4;
extern u32* __GXData;

void fn_801F54D0(float x, float y) {
    float c = lbl_805A38D4;
    float s = lbl_805A38E0;
    float a = s * x;
    u32* gx = __GXData;
    float b = s * y;
    *(float*)((char*)gx + 0x55c) = b;
    *(float*)((char*)gx + 0x560) = c + a;
    *(u32*)((char*)gx + 0x5fc) |= 0x10000000;
}
