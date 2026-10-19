#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Flags {
    u8 hi : 1;
    u8 mid : 1;
    u8 lo : 6;
};

struct S {
    u8 pad[0x4c];
    s32 f4c;
    s32 f50;
    s32 f54;
    s32 f58;
    Flags f5c;
    u8 pad2[3];
    u8 f60;
};

extern "C" void fn_27_B8674(S* p) {
    s32 zero = 0;
    p->f50 = zero;
    p->f4c = -1;
    p->f54 = zero;
    p->f58 = 2;
    p->f5c.hi = 1;
    p->f5c.mid = 0;
    p->f5c.lo = 0xFE;
    p->f60 = (u8)zero;
}
