#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a;
    u32 b;
    u32 p0 : 10;
    u32 f : 5;
    u32 p1 : 17;
};

extern "C" void fn_27_C6FEC(S* p, u32 v) {
    p->f = v;
}
