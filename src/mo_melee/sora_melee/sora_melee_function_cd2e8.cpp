#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" {
void fn_27_CD2E8(u32 *p, u32 v)
{
    Fld *f = (Fld *)&p[2];
    f->b = v;
}
}
