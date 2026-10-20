#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 pad[2];
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" void fn_27_CA540(Fld *p, u32 v)
{
    p->b = v;
}
