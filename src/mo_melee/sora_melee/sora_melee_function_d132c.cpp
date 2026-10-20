#pragma force_active on
typedef unsigned int u32;

struct Hdr {
    u32 a;
    u32 b;
    struct {
        u32 hi : 8;
        u32 lo : 24;
    } c;
};

extern "C" {
void fn_27_D132C(Hdr *p, u32 v)
{
    p->c.hi = v;
}
}
