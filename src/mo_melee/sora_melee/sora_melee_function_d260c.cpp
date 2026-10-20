#pragma force_active on
extern "C" {
typedef unsigned int u32;

struct FlagsBF {
    u32 a : 2;
    u32 f : 2;
    u32 b : 28;
};

void fn_27_D260C(void *self, u32 v)
{
    FlagsBF *p = (FlagsBF *)((char *)self + 8);
    p->f = v;
}
}
