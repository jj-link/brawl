#pragma force_active on
typedef unsigned int u32;

struct Field8 {
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

struct Holder {
    u32 w0;
    u32 w1;
    Field8 f;
};

extern "C" {
void fn_27_CC184(Holder *p, u32 v)
{
    p->f.b = v;
}
}
