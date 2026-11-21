#pragma force_active on
#pragma fp_contract off
#include <types.h>
extern "C" double __frsqrte(double);
extern "C" void** fn_8032EF00(void*);
extern "C" void fn_8032E138(void*, void*);
extern "C" {
extern float lbl_80532550[4];
extern const float lbl_805A1D40, lbl_805A1D44, lbl_805A1D48, lbl_805A1D54, lbl_805A1D58;
}
struct P {
    s16 a, b, c;
    char pad[0xA];
    float q[4] __attribute__((aligned(16)));
    float r[4];
    float s[4];
};
static inline void setvec(float* d, float x, float y, float z, float w) {
    d[0] = x; d[1] = y; d[2] = z; d[3] = w;
}
static inline float magnitude(const float* v) {
    float n = v[2] * v[2] + (v[0] * v[0] + v[1] * v[1]);
    float sc;
    if (n <= lbl_805A1D44) {
        union { u32 i; float f; } u;
        u.i = 0x7f800000;
        sc = u.f;
    } else {
        double estimate = __frsqrte(n);
        float r = (float)estimate;
        sc = (lbl_805A1D54 * r) * (lbl_805A1D58 - r * (n * r));
    }
    return lbl_805A1D48 / sc;
}
static inline void subtract(float* d, const float* a, const float* b) {
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = a[3] - b[3];
}
extern "C" void fn_800986AC(char* p, void* arg) {
    float v[8] __attribute__((aligned(16)));
    float* src = (float*)((char*)*fn_8032EF00(arg) + *(s16*)(p + 0x18) * 0x30);
    *(float*)(p + 0xf0) = src[0];
    *(float*)(p + 0xf4) = src[1];
    *(float*)(p + 0xf8) = src[2];
    *(float*)(p + 0xfc) = src[3];
    setvec(v, *(float*)(p + 0x40), *(float*)(p + 0xe4), *(float*)(p + 0x48), lbl_805A1D44);
    subtract(v + 4, (float*)(p + 0x40), v);
    float dist = magnitude(v + 4);
    *(u8*)(p + 0x4) = 1;
    float lim = *(float*)(p + 0x68) * *(float*)(p + 0x110);
    if (dist >= lim) {
        *(u8*)(p + 0x4) = 0;
        *(float*)(p + 0x44) = *(float*)(p + 0x44) - (dist - lim);
    }
    P tmp;
    tmp.a = -1;
    tmp.b = -1;
    tmp.c = -1;
    tmp.q[0] = lbl_80532550[0];
    tmp.q[1] = lbl_80532550[1];
    tmp.q[2] = lbl_80532550[2];
    tmp.q[3] = lbl_80532550[3];
    tmp.r[0] = lbl_805A1D40;
    tmp.r[1] = lbl_805A1D48;
    tmp.r[2] = lbl_805A1D48;
    tmp.r[3] = lbl_805A1D48;
    tmp.s[0] = lbl_80532550[0];
    tmp.s[1] = lbl_80532550[1];
    tmp.s[2] = lbl_80532550[2];
    tmp.s[3] = lbl_80532550[3];
    tmp.a = *(s16*)(p + 0x14);
    tmp.b = *(s16*)(p + 0x16);
    tmp.c = *(s16*)(p + 0x18);
    float* t = (float*)(p + 0x20);
    tmp.q[0] = t[0];
    tmp.q[1] = t[1];
    tmp.q[2] = t[2];
    tmp.q[3] = t[3];
    tmp.r[0] = t[4];
    tmp.r[1] = t[5];
    tmp.r[2] = t[6];
    tmp.r[3] = t[7];
    tmp.s[0] = t[8];
    tmp.s[1] = t[9];
    tmp.s[2] = t[10];
    tmp.s[3] = t[11];
    fn_8032E138(&tmp, arg);
}
