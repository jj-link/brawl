#pragma force_active on
typedef unsigned int u32;

struct Word2 {
    u32 pad0 : 6;
    u32 f : 3;
    u32 rest : 23;
};

struct Obj {
    u32 w0;
    u32 w1;
    Word2 w2;
};

extern "C" void fn_27_CC8E4(Obj* p, u32 v)
{
    p->w2.f = v;
}
