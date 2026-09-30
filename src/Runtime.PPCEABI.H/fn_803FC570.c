// Runtime.PPCEABI.H/fn_803FC570.c
// MSL integer string conversion wrapper.

typedef unsigned long u32;

typedef struct Pair {
    void* x0;
    u32 x4;
} Pair;

typedef int (*cb_t)(void*, int, int);
extern int fn_803FA078(void*, int, int);
extern int fn_803FBC7C(void*, void*, cb_t, Pair*, void**, int*, int*);
extern int lbl_805A12E0;

int fn_803FC570(void* a, void* b, void* c) {
    Pair ctx;
    void* out;
    int e2, e1;
    int result;

    ctx.x0 = a;
    ctx.x4 = 0;
    result = fn_803FBC7C(c, (void*)((1u << 31) - 1), fn_803FA078, &ctx, &out, &e2,
                         &e1);
    if (b != 0) {
        *(char**)b = (char*)a + (int)out;
    }
    if (e1 != 0) {
        lbl_805A12E0 = 0x22;
        return -1;
    }
    if (e2 != 0) {
        return -result;
    }
    return result;
}
