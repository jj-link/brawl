#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern char *lbl_805A012C;
extern "C" void fn_80166CE8(char *self, char *data);

extern "C" void fn_8005D2E4(char *self)
{
    char *src;

    src = lbl_805A012C + ((u16)*(u32 *)(self + 0x8)) * 0x28;
    *(u32 *)(self + 0x20) = *(u32 *)(src + 0x24);
    *(f32 *)(self + 0xA8) = *(f32 *)(src + 0x0);
    *(f32 *)(self + 0xAC) = *(f32 *)(src + 0x4);
    *(f32 *)(self + 0xB0) = *(f32 *)(src + 0x8);
    *(f32 *)(self + 0x90) = *(f32 *)(src + 0xC);
    *(f32 *)(self + 0x94) = *(f32 *)(src + 0x10);
    *(f32 *)(self + 0x98) = *(f32 *)(src + 0x14);
    *(f32 *)(self + 0x9C) = *(f32 *)(src + 0x18);
    *(f32 *)(self + 0xA0) = *(f32 *)(src + 0x1C);
    *(f32 *)(self + 0xA4) = *(f32 *)(src + 0x20);
    fn_80166CE8(self, src);
}
