#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct Inner {
    u8 pad0[0x58];
    u16 unk58;
    u8 pad1[0x48e - 0x5a];
    u8 unk48e;
};

struct Outer {
    Inner *inner;
    u8 pad[0xa - 4];
    u8 unka;
};

extern "C" void fn_27_111AB8(Outer *p, u16 v) {
    if (p->unka == 1) {
        Inner *in = p->inner;
        if (in->unk58 < 0xffff) {
            in->unk58 = v;
        }
    }
    p->inner->unk48e |= 0x80;
}
