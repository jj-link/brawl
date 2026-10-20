#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct fn_27_2AE128_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_2AE128(fn_27_2AE128_Obj* p)
{
    return (s32)((p->unk8 << 4) & 0xE0000000) >> 30;
}
}
