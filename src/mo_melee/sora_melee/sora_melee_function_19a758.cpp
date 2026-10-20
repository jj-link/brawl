#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_19A758(FnObj* p)
{
    u32 x = p->unk8;
    return (s32)(((x >> 25) & 0xF) << 28) >> 29;
}
}
