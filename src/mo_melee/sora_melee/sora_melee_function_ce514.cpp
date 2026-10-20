#pragma force_active on
typedef unsigned int u32;

struct Bits8 {
    u32 hi : 5;
    u32 f : 5;
    u32 lo : 22;
};

extern "C" void fn_27_CE514(void *obj, u32 val)
{
    Bits8 *b = (Bits8 *)((char *)obj + 0x8);
    b->f = val;
}
