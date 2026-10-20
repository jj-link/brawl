#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 w0;
    u32 w1;
    u32 a : 4;
    u32 f : 4;
    u32 rest : 24;
};

extern "C" {
void fn_27_1A561C(S* p, u32 v) {
    p->f = v;
}
}
