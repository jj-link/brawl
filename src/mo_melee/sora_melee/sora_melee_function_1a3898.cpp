#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 bits;
};

extern "C" {
s32 fn_27_1A3898(Obj* obj)
{
    return (s32)((obj->bits << 10) & 0xFFE00000u) >> 22;
}
}
