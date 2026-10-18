#pragma force_active on
typedef unsigned char u8;

struct Inner {
    int unk0;
    void* unk4;
};

struct Outer {
    Inner* unk0;
    u8 unk4;
};

extern "C" void* fn_41_A1E4(Outer* p) {
    if (p->unk4 == 1) {
        return 0;
    }
    return p->unk0->unk4;
}
