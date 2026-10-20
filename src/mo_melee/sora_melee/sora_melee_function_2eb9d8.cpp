#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_2EB9D8_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_2EB9D8(fn_27_2EB9D8_obj *p)
{
    u32 x = p->unk8;
    u32 r = (x << 3) | (x >> 29);
    return (s32)(r & 0xF0000000) >> 29;
}
}
