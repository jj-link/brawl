#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct E {
    u8 pad0[0x55];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct S {
    u8 pad0[0x6];
    u16 count;
    u8 pad8[0x10];
    u8* f18;
};

extern "C" void fn_8011176C(S* p, int flag) {
    E* e;
    u32 off;
    u32 i;
    i = 0;
    off = 0;
    while (i < p->count) {
        e = (E*)(p->f18 + off);
        e->b1 = flag;
        i++;
        off += 0x60;
    }
}
