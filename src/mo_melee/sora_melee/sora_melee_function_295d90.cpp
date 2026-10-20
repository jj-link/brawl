#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_295D90_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_295D90(fn_27_295D90_arg* p)
{
    u32 x = p->unk8;
    s32 r = (s32)(((x << 4) | (x >> 28)) & 0xF8000000u);
    return r >> 28;
}
}
