#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Inner {
    u32 unk0;
    u32 unk4;
};

struct Outer {
    Inner* unk0;
    u8 unk4;
};

extern "C" u32 fn_41_A25C(Outer* p) {
    if (p->unk4 == 1) {
        return 0;
    }
    return p->unk0->unk4;
}
