#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct FooObj {
    u8 pad0[0x1];
    u8 flags;
    u8 pad2[0xE];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" int fn_27_2D6C18(FooObj* p, int a, int b) {
    if (a != 0 && p->unk10 > p->unk18) {
        p->flags |= 0x10;
    } else {
        p->flags &= ~0x10;
    }

    if (b != 0) {
        p->flags |= 0x20;
    } else {
        p->flags &= ~0x20;
    }

    p->flags |= 0x8;
    return (p->flags >> 4) & 1;
}
