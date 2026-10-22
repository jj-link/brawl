#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern char *lbl_805A012C;

extern "C" void fn_8005D27C(char *src)
{
    char *dst;

    dst = lbl_805A012C + ((u16)*(u32 *)(src + 0x8)) * 0x28;
    *(u32 *)(dst + 0x24) = *(u32 *)(src + 0x20);
    *(f32 *)(dst + 0x0) = *(f32 *)(src + 0xA8);
    *(f32 *)(dst + 0x4) = *(f32 *)(src + 0xAC);
    *(f32 *)(dst + 0x8) = *(f32 *)(src + 0xB0);
    *(f32 *)(dst + 0xC) = *(f32 *)(src + 0x90);
    *(f32 *)(dst + 0x10) = *(f32 *)(src + 0x94);
    *(f32 *)(dst + 0x14) = *(f32 *)(src + 0x98);
    *(f32 *)(dst + 0x18) = *(f32 *)(src + 0x9C);
    *(f32 *)(dst + 0x1C) = *(f32 *)(src + 0xA0);
    *(f32 *)(dst + 0x20) = *(f32 *)(src + 0xA4);
}
