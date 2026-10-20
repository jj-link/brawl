#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a;
    u32 b;
    struct {
        u32 hi : 4;
        u32 rest : 28;
    } c;
};

extern "C" void fn_27_CD264(S* s, u32 v) {
    s->c.hi = v;
}
