#include <types.h>
#pragma force_active on

extern "C" u32 fn_80285B30(void* ptr, f32 val);
extern "C" f32 lbl_805A47F0, lbl_805A47F4, lbl_805A47F8, lbl_805A47FC;

static inline s32 nz(s32 x) {
    return (s32)((u32)(-x | x) >> 31);
}

extern "C" u32 fn_80325C48(void* arg0) {
    s32 a = 0;
    union { s32 signedValue; u32 value; } one;
    one.signedValue = 1;
    if (nz(one.value)) {
        if (nz((s8)(fn_80285B30((char*)arg0 + 0x20, lbl_805A47F8) >> 24)))
            a = 1;
    }
    s32 b = 0;
    if (nz(a)) {
        if (nz((s8)(fn_80285B30((char*)arg0 + 0x60, lbl_805A47F8) >> 24)))
            b = 1;
    }
    s32 c = 0;
    if (nz(b) && lbl_805A47F4 == *(f32*)((char*)arg0 + 0x118))
        c = 1;
    s32 d = 0;
    if (nz(c) && *(f32*)((char*)arg0 + 0x11c) >= lbl_805A47F0)
        d = 1;
    s32 e = 0;
    if (nz(d) && *(f32*)((char*)arg0 + 0x11c) < lbl_805A47FC)
        e = 1;
    s32 f = 0;
    if (nz(e) && *(f32*)((char*)arg0 + 0x12c) <= *(f32*)((char*)arg0 + 0x130))
        f = 1;
    s32 g = 0;
    if (nz(f) && *(f32*)((char*)arg0 + 0x104) <= *(f32*)((char*)arg0 + 0x108))
        g = 1;
    return (u32)g << 24;
}
