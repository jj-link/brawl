#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad0 : 4;
    u32 f : 4;
    u32 rest : 24;
};

extern "C" void fn_27_41A1C(S* p, u32 v) {
    p[2].f = v;
}
