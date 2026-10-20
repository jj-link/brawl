#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct BitfieldHolder {
    u32 pad0 : 10;
    s32 field : 5;
    u32 pad1 : 17;
};

struct Holder {
    u32 unk0;
    u32 unk4;
    BitfieldHolder bits;
};

extern "C" {
s32 fn_27_29604C(Holder* p)
{
    return p->bits.field;
}
}
