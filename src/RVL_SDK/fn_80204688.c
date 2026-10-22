#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
extern void fn_80203E4C(u32 a, u32 b, u32 c, u32 d, u32 e);

typedef struct Hdr {
    char pad0[0x18];
    u32 p18;
    u32 p1c;
    char pad20[0x1c];
    u32 p3c;
    u32 p40;
    u32 p44;
    u32 p48;
    u16 s4c;
    u16 s4e;
} Hdr;

typedef struct Blk {
    u16 a;
    u16 b;
    u32 c;
    u32 d;
    u32 e;
} Blk;

Hdr* fn_80204688(u32 start, u32 size, u32 arg2) {
    u32 end = (size + start) & ~3;
    Hdr* h = (Hdr*)((start + 3) & ~3);
    Blk* b;
    u32 e1;
    if ((u32)h > end || end - (u32)h < 0x64) {
        return 0;
    }
    fn_80203E4C((u32)h, 0x45585048, (u32)h + 0x50, end, arg2);
    h->s4c = 0;
    h->s4e = 0;
    b = (Blk*)h->p18;
    e1 = h->p1c;
    b->a = 0x4652;
    b->b = 0;
    b->c = e1 - ((u32)b + 0x10);
    b->d = 0;
    b->e = 0;
    h->p3c = (u32)b;
    h->p40 = (u32)b;
    h->p44 = 0;
    h->p48 = 0;
    return h;
}