// Runtime.PPCEABI.H/fn_803FC618.c
// MSL signed integer string conversion wrapper.

typedef unsigned long u32;

typedef struct Pair {
    void* x0;
    u32 x4;
} Pair;

typedef int (*cb_t)(void*, int, int);
extern int fn_803FA078(void*, int, int);
extern int fn_803FBC7C(void*, void*, cb_t, Pair*, void**, int*, int*);
extern int lbl_805A12E0;

int fn_803FC618(void* a, void* b, void* c) {
    Pair ctx;
    void* out;
    int e2, e1;
    int result;
    u32 limit;

    ctx.x0 = a;
    ctx.x4 = 0;
    result = fn_803FBC7C(c, (void*)((1u << 31) - 1), fn_803FA078, &ctx, &out, &e2,
                         &e1);
    if (b != 0) {
        *(char**)b = (char*)a + (int)out;
    }
    limit = (1u << 31) - 1;
    if (e1 != 0 || (e2 == 0 && (u32)result > limit) ||
        (e2 != 0 && (u32)result > (1u << 31))) {
        result = e2 != 0 ? (int)(1u << 31) : (int)((1u << 31) - 1);
        lbl_805A12E0 = 0x22;
        return result;
    }
    return e2 != 0 ? -result : result;
}
