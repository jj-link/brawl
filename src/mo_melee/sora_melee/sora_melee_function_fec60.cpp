#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 a : 7;
    u32 b : 7;
    u32 c : 18;
};

extern "C" {
void fn_27_FEC60(Obj *p, u32 v)
{
    p->b = v;
}
}
