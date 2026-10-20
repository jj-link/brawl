#pragma force_active on
typedef unsigned int u32;

struct Inner {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct Outer {
    u32 unk0;
    Inner *unk4;
};

extern "C" {
u32 fn_27_B1E5C(Outer *p)
{
    return (p->unk4->unk8 >> 20) & 7;
}
}
