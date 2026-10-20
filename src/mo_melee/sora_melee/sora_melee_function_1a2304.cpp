#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" {
void fn_27_1A2304(void *self, u32 v)
{
    Flags *p = (Flags *)((char *)self + 8);
    p->b = v;
}
}
