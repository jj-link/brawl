#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 hi : 10;
    u32 lo : 22;
};

extern "C" {
void fn_27_1A6538(void *p, u32 v)
{
    Fld *f = (Fld *)((char *)p + 8);
    f->hi = v;
}
}
