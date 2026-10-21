#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 pad0[0x74];
    s32 unk74;
    u8 pad1[0xA0 - 0x78];
    s32 unkA0;
};

extern "C" {
s32 fn_8030EA88(Obj *arg0) {
    s32 d = arg0->unk74 - arg0->unkA0;
    return ((d << 1) * 0xC) + 0x24;
}
}
