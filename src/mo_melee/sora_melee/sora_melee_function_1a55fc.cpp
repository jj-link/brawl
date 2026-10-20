#pragma force_active on
extern "C" {
typedef unsigned int u32;

struct S {
    u32 a;
    u32 b;
    u32 hi : 4;
    u32 rest : 28;
};

void fn_27_1A55FC(S *p, u32 v) {
    p->hi = v;
}
}
