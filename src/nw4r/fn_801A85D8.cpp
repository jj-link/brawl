#include <types.h>
#pragma force_active on

extern "C" {
void fn_801628B4(void* a, void* b, void* c);
void fn_80162908(void* a, void* b, f32* v, f32 x, f32 y);
void fn_801EC184(void* a, void* b);
void fn_801EC1B8(void* a, void* b, void* c);
void fn_801EC8DC(void* a, f32* v, f32 x, f32 y, f32 z);
extern f32 lbl_805A3398;
}

extern "C" u32 fn_801A85D8(void* a, f32* b, void* c, f32* d, u32 flags, u8* s) {
    f32 v8[3];
    f32 v18[12];
    u32 fl;
    u32 r;
    u32 ret;
    f32 k;
    f32 f2;
    f32 f1;
    f32 f0;

    fl = *(u32*)s;
    if ((fl & 2) || (fl & 4)) {
        if (flags & 0x40000000) {
            fn_801EC184(c, a);
        } else {
            fn_801628B4(a, c, d);
        }
    } else if (fl & 0x20) {
        if (flags & 0x40000000) {
            f2 = *(f32*)(s + 0x48);
            f1 = *(f32*)(s + 0x38);
            f0 = *(f32*)(s + 0x28);
            v8[1] = f1;
            v8[0] = f0;
            v8[2] = f2;
            fn_80162908(a, c, v8, f1, f2);
        } else {
            fn_801EC8DC(s + 0x1C, v18, d[0], d[1], d[2]);
            fn_801EC1B8(c, v18, a);
        }
    } else if (flags & 0x40000000) {
        fn_801EC1B8(c, s + 0x1C, a);
    } else {
        fn_801628B4(a, c, d);
        fn_801EC1B8(a, s + 0x1C, a);
    }

    if (fl & 8) {
        r = flags | 0x40000000;
        k = lbl_805A3398;
        b[2] = k;
        b[1] = k;
        b[0] = k;
    } else {
        r = flags & 0x3FFFFFFF;
        f0 = *(f32*)(s + 0x4);
        f1 = *(f32*)(s + 0x8);
        f2 = *(f32*)(s + 0xC);
        b[0] = f0;
        b[1] = f1;
        b[2] = f2;
    }

    ret = r & 0x0FFFFFFF;
    if (fl & 0x10) {
        ret = r | 0x10000000;
    }
    return ret;
}
