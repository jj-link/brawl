#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct UnkObj {
    char pad[8];
    u32 unk8;
};

extern "C" s32 fn_27_295F20(UnkObj* p)
{
    return (s32)((p->unk8 << 3) & 0xF0000000) >> 29;
}
