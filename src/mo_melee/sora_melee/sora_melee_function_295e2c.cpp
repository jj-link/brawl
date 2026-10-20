#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 w0;
    u32 w1;
    struct {
        u32 hi : 8;
        u32 f : 4;
        u32 lo : 20;
    } flags;
};

extern "C" void fn_27_295E2C(S* p, u32 v) {
    p->flags.f = v;
}
