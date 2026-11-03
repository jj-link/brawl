#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 f8;
} S;

extern u8 lbl_8040D990[0x10];

void *fn_8023DCCC(S *a, S *b, S *c) {
    u8 a8;
    u8 b8;
    u8 idx;
    u8 action;

    if (a == 0) {
        *c = *b;
        return b;
    }

    b8 = b->f8;
    if (b8 == 0 || (a8 = a->f8) == 0) {
        return 0;
    }

    if (a8 & 0x10) {
        *c = *a;
        c->f8 = c->f8 & ~0x10;
        return c;
    }

    if (b8 & 0x10) {
        *c = *b;
        c->f8 = c->f8 & ~0x10;
        return c;
    }

    idx = (u8)(b8 + 3 * (a8 - 1) - 1);
    action = lbl_8040D990[idx];

    switch (action) {
    case 1:
        *c = *a;
        return a;
    case 2:
        *c = *b;
        return b;
    case 3:
        c->f8 = a8;

        c->f0 = (a->f0 < b->f0) ? a->f0 : b->f0;
        c->f2 = (a->f2 > b->f2) ? a->f2 : b->f2;

        if (c->f0 < c->f2) {
            return 0;
        }

        if (c->f8 == 2) {
            c->f4 = (a->f4 > b->f4) ? a->f4 : b->f4;
            c->f6 = (a->f6 > b->f6) ? a->f6 : b->f6;
        }

        return c;
    default:
        return 0;
    }
}
