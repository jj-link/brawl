#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_1982F8(void *p, u32 v)
{
    Flags *f = (Flags *)((char *)p + 8);
    f->hi = v;
}
}
