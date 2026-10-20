#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 bits;
};

extern "C" {
s32 fn_27_10DFB0(Obj* p)
{
    u32 x = p->bits;
    return (s32)((x << 10) & 0xFC000000) >> 27;
}
}
