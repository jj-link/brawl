#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Fn1D4B0Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" s32 fn_27_1D4B0(Fn1D4B0Obj* obj)
{
    return (s32)((obj->flags << 2) & 0xE0000000) >> 30;
}
