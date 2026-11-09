#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct C { u8 r, g, b, a; };
extern "C" void fn_8018C464(C* dst, C src, u32 alpha) {
    *dst = src;
    if (alpha != 0xFF) {
        dst->a = (int)(src.a * alpha) / 255;
    }
}
