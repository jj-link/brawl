#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u32 x : 2;
    u32 y : 2;
    u32 z : 28;
} S;

extern "C" void fn_27_1D0604(S* p, u32 v) {
    p->y = v;
}
