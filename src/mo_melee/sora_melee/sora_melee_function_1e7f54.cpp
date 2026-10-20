#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 pad[2];
    u32 flags;
};

extern "C" s32 fn_27_1E7F54(Obj* p)
{
    u32 v = p->flags;
    u32 rot = (v << 8) | (v >> 24);
    return (s32)(rot & 0xF8000000) >> 28;
}
