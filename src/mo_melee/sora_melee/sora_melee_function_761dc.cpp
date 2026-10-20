#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
};

extern "C" {
s32 fn_27_761DC(Obj* p)
{
    u32 x = (u32)p->unk8;
    u32 r = (x << 5) | (x >> 27);
    return ((s32)(r & 0xFC000000)) >> 27;
}
}
