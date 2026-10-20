#pragma force_active on
typedef unsigned int u32;

struct BitS {
    u32 pad[2];
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" void fn_27_CB894(BitS *p, u32 v)
{
    p->b = v;
}
