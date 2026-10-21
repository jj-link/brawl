#pragma force_active on
typedef float f32;
typedef unsigned int u32;

extern unsigned char* __GXData;

void fn_801F5484(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    unsigned char* gx = __GXData;
    *(f32*)(gx + 0x544) = farg0;
    *(f32*)(gx + 0x548) = farg1;
    *(f32*)(gx + 0x54C) = farg2;
    *(f32*)(gx + 0x550) = farg3;
    *(f32*)(gx + 0x554) = farg4;
    *(f32*)(gx + 0x558) = farg5;
    *(u32*)(gx + 0x5FC) |= 0x10000000;
}
