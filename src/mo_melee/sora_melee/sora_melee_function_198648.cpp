#pragma force_active on
typedef unsigned int u32;

struct Bits8 {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_198648(void *obj, u32 val)
{
    Bits8 *w = (Bits8 *)((char *)obj + 8);
    w->b = val;
}
}
