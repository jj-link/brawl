#pragma force_active on
typedef unsigned int u32;

struct Word {
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

struct Outer {
    u32 pad0;
    u32 pad1;
    Word w;
};

extern "C" void fn_27_29590C(Outer* p, u32 v) {
    p->w.b = v;
}
