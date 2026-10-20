#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 a : 20;
    u32 b : 10;
    u32 c : 2;
};

extern "C" {
void fn_27_1A67C4(u32 *obj, u32 v)
{
    Fld *f = (Fld *)&obj[2];
    f->b = (v << 2) >> 2;
}
}
