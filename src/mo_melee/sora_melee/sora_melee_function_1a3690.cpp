#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj08 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1A3690(Obj08* p)
{
    return (s32)((p->unk8 & 0x003FF800) << 10) >> 22;
}
}
