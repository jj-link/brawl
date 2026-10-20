#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_385CF8_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_385CF8(fn_27_385CF8_Obj *p)
{
    u32 v = (p->unk8 << 6) & 0xF0000000;
    return (s32)v >> 29;
}
}
