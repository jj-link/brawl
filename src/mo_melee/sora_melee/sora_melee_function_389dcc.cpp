#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Bits {
    u32 pad : 4;
    s32 f : 4;
    u32 rest : 24;
};

struct Holder {
    int unk0;
    int unk4;
    Bits bits;
};

extern "C" {
s32 fn_27_389DCC(Holder* p) {
    return p->bits.f;
}
}
