#pragma force_active on
#include <nw4r/ut/ut_algorithm.h>

extern "C" {
void fn_80191930(int, int, f32*, s8, f32, f32, f32, f32, f32, f32);
void fn_80199938(int*, void*);
void fn_801A4D08(f32*, int, void*, int, int);
double fn_80400778(double, int);
}

extern f32 lbl_805A3298;
extern double lbl_805A32A0;

extern "C" void fn_801999D4(int* arg0, int arg1, void* arg2) {
    f32 v[12];
    f32 base;
    f32 m;
    f32 s;
    int spC;
    char* p;
    u32 mask;
    int i;
    s8 e;
    union {
        f32 f;
        u32 u;
    } conv;

    spC = *arg0;
    fn_80199938(&spC, arg2);
    mask = *(u32*)((char*)arg2 + 4);
    p = (char*)arg2 + 0xAC;
    base = lbl_805A3298;
    i = 8;
    while (mask != 0) {
        if (mask & 1) {
            fn_801A4D08(v, 1, p, mask & 0xF, 0);
            m = nw4r::ut::Max(base, nw4r::ut::Abs(v[0]));
            m = nw4r::ut::Max(m, nw4r::ut::Abs(v[1]));
            m = nw4r::ut::Max(m, nw4r::ut::Abs(v[3]));
            m = nw4r::ut::Max(m, nw4r::ut::Abs(v[4]));
            m = nw4r::ut::Max(m, nw4r::ut::Abs(v[5]));
            m = nw4r::ut::Max(m, nw4r::ut::Abs(v[7]));
            conv.f = m;
            e = (s8)(((conv.u >> 23) & 0xFF) - 0x7E);
            s = (f32)fn_80400778(lbl_805A32A0, -e);
            f32 a3 = v[3];
            f32 t0 = v[0] * s;
            v[0] = t0;
            f32 t1 = v[1] * s;
            v[1] = t1;
            f32 t3 = a3 * s;
            v[2] = t3;
            f32 t4 = v[4] * s;
            v[4] = t4;
            f32 t5 = v[5] * s;
            v[5] = t5;
            f32 t7 = v[7] * s;
            v[6] = t7;
            fn_80191930(arg1, i - 7, v, e, t5, t4, t3, t1, t0, s);
        }
        mask = mask >> 4;
        p += 0x14;
        i++;
    }
}
