#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1A5670_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1A5670(fn_27_1A5670_Obj* p)
{
    return (s32)((p->unk8 & 0x00F80000) << 8) >> 28;
}
}
