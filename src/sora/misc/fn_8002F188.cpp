#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_805A1570;
extern const f32 lbl_805A1574;
extern const f32 lbl_805A1578;
extern const f32 lbl_805A157C;
extern const f32 lbl_805A1580;
extern const f32 lbl_805A1584;
extern const f32 lbl_805A1588;
}

static inline void convert(u8 y, u8 u, u8 v, u8& r, u8& g, u8& b) {
    s32 red = (s32)(lbl_805A1570 * ((f32)y - lbl_805A1574) + lbl_805A1578 * ((f32)v - lbl_805A157C));
    s32 green = (s32)(lbl_805A1570 * ((f32)y - lbl_805A1574) - lbl_805A1580 * ((f32)u - lbl_805A157C) - lbl_805A1584 * ((f32)v - lbl_805A157C));
    s32 blue = (s32)(lbl_805A1570 * ((f32)y - lbl_805A1574) + lbl_805A1588 * ((f32)u - lbl_805A157C));
    s32 red0 = red & ((-red & ~red) >> 31);
    r = red0 < 255 ? red0 : 255;
    s32 green0 = green & ((-green & ~green) >> 31);
    g = green0 < 255 ? green0 : 255;
    s32 blue0 = blue & ((-blue & ~blue) >> 31);
    b = blue0 < 255 ? blue0 : 255;
}

extern "C" void fn_8002F188(s32 stride, const u8* src, u8* dst) {
    u8* ar = dst;
    u8* gb = dst + 0x20;
    s32 offset = 0;
    for (u32 i = 0; i < 4; ++i) {
        const u8* in = src + offset;
        for (s32 j = 0; j < 2; ++j) {
            u8 r, g, b;
            convert(in[0], in[1], in[3], r, g, b);
            ar[0] = 255;
            ar[1] = r;
            gb[0] = g;
            gb[1] = b;
            convert(in[2], in[1], in[3], r, g, b);
            ar[2] = 255;
            ar[3] = r;
            gb[2] = g;
            gb[3] = b;
            in += 4;
            ar += 4;
            gb += 4;
        }
        offset += stride;
    }
}