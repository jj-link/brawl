#pragma force_active on
// Runtime.PPCEABI.H/atoi.c
typedef unsigned long u32;
typedef struct Pair { void* x0; u32 x4; } Pair;
typedef int (*cb_t)(void*, int, int);
extern int fn_803FA078(void*, int, int);
extern u32 fn_803FBC7C(int, int, cb_t, Pair*, void**, int*, int*);
extern int lbl_805A12E0;
int atoi(int arg0) {
    Pair ctx;
    int e1;
    int e2;
    void* out;
    u32 result;
    ctx.x0 = (void*)arg0;
    ctx.x4 = 0;
    result = fn_803FBC7C(10, 0x7FFFFFFF, fn_803FA078, &ctx, &out, &e2, &e1);
    if (e1 != 0 || (e2 == 0 && result > 0x7FFFFFFFU) ||
        (e2 != 0 && result > 0x80000000U)) {
        int saturated = e2 ? (int)0x80000000U : 0x7FFFFFFF;
        lbl_805A12E0 = 0x22;
        return saturated;
    }
    if (e2 != 0) result = -result;
    return (int)result;
}