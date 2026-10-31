#pragma force_active on
#pragma use_lmw_stmw on

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct S {
    u8 pad[0x1806];
    u16 f;
} S;

typedef struct A {
    S *ptr;
    s32 unk4;
    u8 pad08[4];
    u16 c1;
    u16 c2;
    s32 unk10;
    u8 pad14[4];
    s32 unk18;
    u16 max2;
    u16 max1;
    u8 b1;
    u8 b2;
    u8 pad22[0x26];
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
} A;

extern s32 fn_802629B8(s32, s32, S *, s32 *);
extern s32 fn_80262CF0(S *);
extern s32 fn_80261224(void *);
extern s32 fn_80263E18(S *);

s32 fn_80262444(A *arg0, s32 arg1, s32 arg2) {
    u8 sp8[0x180];
    S *p;
    u16 c1;
    u16 max2;
    u16 c2;
    u16 max1;
    u8 b1;
    u8 b2;
    s32 counter;
    s32 base;
    s32 r;

    p = arg0->ptr;
    if (p == 0)
        return -1;

    counter = 0;
    base = arg2 + arg0->v1 * arg0->v2;
    arg0->unk58 = arg2;
    c1 = arg0->c1;
    arg0->unk64 = arg2;
    c2 = arg0->c2;
    arg0->unk5C = base;
    max2 = arg0->max2;
    max1 = arg0->max1;
    b1 = arg0->b1;
    b2 = arg0->b2;
    arg0->unk60 = base + arg0->v3 * arg0->v4;

    goto outer_check;

inner_body:
    r = fn_802629B8(c1 * b1, c2 * b2, p, (s32 *)sp8);
    if (r < 0)
        goto err_handler;
    c1++;
    counter++;

inner_check:
    if (c1 < max2 && counter < arg1)
        goto inner_body;
    if (max2 == c1) {
        c1 = 0;
        c2++;
    }

outer_check:
    if (c2 < max1 && counter < arg1)
        goto inner_check;
    if (max1 == c2 && c1 == 0) {
        r = fn_80262CF0(p);
        if (r < 0)
            return r;
    }

    arg0->c1 = c1;
    arg0->c2 = c2;
    r = fn_80261224(p);
    arg0->unk10 = r;
    return arg0->unk18 - c2 * max2 - c1;

err_handler:
    if (p->f != 0 && r != -0xF0) {
        arg0->unk4 = r;
        r = fn_80263E18(p);
    }
    return r;
}
