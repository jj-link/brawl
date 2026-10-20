#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_19B2F8(Obj* p)
{
    u32 t = p->unk8;
    t = (t << 5) | (t >> 27);
    t &= 0xFC000000;
    return (s32)t >> 27;
}
}
