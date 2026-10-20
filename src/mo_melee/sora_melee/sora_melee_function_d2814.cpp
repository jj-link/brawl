#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FooObj {
    char pad[8];
    u32 field8;
};

extern "C" {
s32 fn_27_D2814(FooObj* p)
{
    u32 x = p->field8;
    s32 t = (s32)(((x << 5) | (x >> 27)) & 0xFC000000u);
    return t >> 27;
}
}
