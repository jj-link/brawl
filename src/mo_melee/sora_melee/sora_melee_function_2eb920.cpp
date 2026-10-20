#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" {
void fn_27_2EB920(void *p, u32 v)
{
    Flags *f = (Flags *)((char *)p + 8);
    f->b = v;
}
}
