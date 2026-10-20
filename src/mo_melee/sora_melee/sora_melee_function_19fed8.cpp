#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_19FED8_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_19FED8(struct fn_27_19FED8_arg *p)
{
    u32 x = p->unk8;
    u32 t = (x << 4) | (x >> 28);
    t &= 0xF8000000;
    return (s32)t >> 28;
}
}
