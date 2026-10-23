#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Bits {
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
    u8 b6:1;
    u8 b7:1;
};

struct S {
    u8 pad0[0x6];
    u16 count;
    u8 pad8[0x10];
    u8* base;
};

extern "C" void fn_801117A4(S* p, s32 flag) {
    Bits* e;
    s32 off;
    u32 i;
    i = 0;
    off = 0;
    while (i < p->count) {
        e = (Bits*)(p->base + off + 0x54);
        i++;
        off += 0x60;
        e->b7 = flag;
    }
}
