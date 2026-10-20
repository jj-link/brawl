#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 hi : 7;
    u32 rest : 25;
} FnBits;

extern "C" void fn_27_1D0474(FnBits *p, u32 v) {
    p->hi = v;
}
