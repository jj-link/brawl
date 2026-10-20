#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a : 2;
    u32 f : 2;
    u32 rest : 28;
};

extern "C" {
void fn_27_FF390(S *p, u32 v) {
    p[2].f = v;
}
}
