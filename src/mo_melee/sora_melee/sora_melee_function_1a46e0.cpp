#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 a : 10;
    u32 f : 10;
    u32 b : 12;
};

extern "C" void fn_27_1A46E0(S* p, u32 v) {
    p->f = v;
}
