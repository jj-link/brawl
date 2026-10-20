#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_19D8B4_Arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_19D8B4(struct fn_27_19D8B4_Arg *p)
{
    u32 x = p->unk8;
    u32 y = (x << 5) | (x >> 27);
    y &= 0xFC000000;
    return (s32)y >> 27;
}
}
