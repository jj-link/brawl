#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 flags;
};

extern "C" s32 fn_27_1A40B8(Obj* p)
{
    return (s32)((p->flags >> 25 & 0xF) << 28) >> 29;
}
