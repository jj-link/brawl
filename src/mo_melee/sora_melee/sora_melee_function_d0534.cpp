#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_D0534(void *self) {
    struct X {
        u32 a : 21;
        u32 b : 1;
    };
    X *x = (X*)((u32*)self + 2);
    return x->b;
}
