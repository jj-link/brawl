#pragma force_active on
typedef unsigned int u32;

struct Bf {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" {
void fn_27_1D608(u32* p, u32 v)
{
    Bf* s = (Bf*)&p[2];
    s->b = v;
}
}
