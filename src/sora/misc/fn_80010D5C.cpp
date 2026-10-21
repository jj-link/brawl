#include <types.h>
#pragma force_active on

struct Pair {
    int x, y;
};

struct Obj {
    int a, b, c, d, e, f, g;
    unsigned char flags, flag1d;
    unsigned char pad[2];
    Pair pair;
    void* ptr;
    float x, y, z, w;
    int id;
    unsigned char r, green, blue, alpha;
    void* vtable;
};

extern int lbl_804207DC[7];
extern int lbl_8059FF88;
extern int lbl_8059C428;
extern void* lbl_8059FF90;
extern const float lbl_805A1398;
extern const float lbl_805A139C;

extern "C" void fn_80012470(void*, Obj*);

extern "C" Obj* fn_80010D5C(Obj* p, const Pair* q, unsigned int mode) {
    p->vtable = &lbl_804207DC;
    p->a = 0;
    p->b = 0;
    p->c = -1;
    p->d = 0;
    p->flags = (p->flags | 0xC0) & ~0x30;
    p->flag1d = 0;
    p->pair = *q;
    p->ptr = &lbl_8059FF88;
    p->id = -1;
    p->r = 0x80;
    p->green = 0xC0;
    p->blue = 0x40;
    p->alpha = 0x80;

    int next = lbl_8059C428;
    p->e = next;
    p->f = next;
    lbl_8059C428 = next + 1;

    p->x = lbl_805A1398;
    p->y = lbl_805A1398;
    p->z = lbl_805A139C;
    p->w = lbl_805A139C;

    if (mode == 1 && !((p->flags >> 4) & 1)) {
        fn_80012470(lbl_8059FF90, p);
        p->flags |= 0x10;
    }

    return p;
}
