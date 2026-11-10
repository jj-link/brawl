#include <types.h>
#pragma force_active on

extern const float lbl_805A2D78;
extern const float lbl_805A2D7C;
extern const float lbl_805A2D8C;
extern const float lbl_805A2DA8;

extern "C" u16 fn_80170150(u16 a, u16 v, void* p, f32 f) {
    u16 ret = v;
    if (lbl_805A2D78 != f) {
        u32 s = *(u32*)((char*)p + 0xEC) * 0x343FD + 0x269EC3;
        *(u32*)((char*)p + 0xEC) = s;
        f32 ratio = (f32)(s >> 16) / lbl_805A2D7C;
        f32 t = f * ((f32)v * ratio);
        if ((f32)v - t < lbl_805A2D8C) {
            ret = 1;
        } else if ((f32)v - t > lbl_805A2DA8) {
            ret = 0xFFFF;
        } else {
            ret = v - (s32)t;
        }
    }
    return ret;
}
