#pragma force_active on
typedef unsigned int u32;

struct Inner {
    u32 w0;
    u32 w1;
    u32 pad : 3;
    u32 f : 3;
    u32 rest : 26;
};

struct Outer {
    u32 a;
    Inner *p;
};

extern "C" void fn_27_B1D60(Outer *o, u32 v) {
    o->p->f = v;
}
