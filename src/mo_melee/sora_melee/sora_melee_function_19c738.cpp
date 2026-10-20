#pragma force_active on
typedef unsigned int u32;

struct Bf {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_19C738(u32 *p, u32 v)
{
    ((struct Bf *)&p[2])->b = v;
}
}
