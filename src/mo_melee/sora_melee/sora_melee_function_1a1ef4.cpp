#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 bits;
};

extern "C" {
s32 fn_27_1A1EF4(Obj* p)
{
    u32 v = (p->bits >> 23) & 0x1F;
    return (s32)(v << 27) >> 28;
}
}
