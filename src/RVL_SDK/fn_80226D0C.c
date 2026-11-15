#pragma force_active on
#pragma opt_unroll_loops off
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef float f32;
typedef double f64;

extern double fn_80400D94(float);
extern s8 fn_802261EC(void *);
extern s8 fn_802263D4(void *);
extern s8 fn_802265FC(void *);
extern s8 fn_802267B0(void *);
extern void fn_80226924(void *, s8);
extern const float lbl_805A39F8;
extern const float lbl_8059ED50;
extern const float lbl_8059ED54;
extern const float lbl_805A3A10;
extern const float lbl_805A3A14;
extern const float lbl_805A3A18;

typedef struct { s16 x; s16 y; u16 act; u16 pad; } In;
typedef struct { f32 x; f32 y; s8 flag; u8 flag2; char pad[2]; } Ent;

typedef struct Obj {
    char _0[0x54];
    f32 unk54;
    char _58[0x5E - 0x58];
    s8 unk5E;
    char _5F[0xB0 - 0x5F];
    f32 unkB0;
    f32 unkB4;
    char _B8[0xC4 - 0xB8];
    Ent ents[4];
    f32 unkF4;
    f32 unkF8;
    u8 unkFC;
    char _FD[3];
    f32 unk100;
    f32 unk104;
    u8 unk108;
    char _109[3];
    s16 unk10C;
    char _10E[0x490 - 0x10E];
    f32 unk490;
    f32 unk494;
    f32 unk498;
    f32 unk49C;
    f32 unk4A0;
    char _4A4[0x4B0 - 0x4A4];
    f32 unk4B0;
    f32 unk4B4;
    f32 unk4B8;
    f32 unk4BC;
    char _4C0[0x4C8 - 0x4C0];
    u16 unk4C8;
    u8 unk4CA;
    char _4CB[0x4F4 - 0x4CB];
    f32 unk4F4;
    f32 unk4F8;
    f32 unk4FC;
    f32 unk500;
    char _504[0x510 - 0x504];
    f32 unk510;
} Obj;

typedef struct InObj {
    char _0[8];
    In in[4];
    char _28[0x36 - 0x28];
    u8 kind;
} InObj;

void fn_80226D0C(Obj *o, InObj *arg1) {
    s8 r30;
    s8 k;
    f32 dy;
    f32 dx;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 t;
    f32 len;
    u8 f2;
    In *pi;
    Ent *pe;
    Ent *pf;
    Ent *pg;
    Ent *end;

    if (arg1->kind == 2 || arg1->kind == 5 || arg1->kind == 8) {
        pe = &o->ents[3];
        pi = &arg1->in[3];
        do {
            if (pi->act != 0) {
                pe->x = lbl_805A3A10 * (f32)pi->x - lbl_805A3A14;
                pe->y = lbl_805A3A10 * (f32)pi->y - lbl_805A3A18;
                pe->flag = 0;
                pe->flag2 = 0;
            } else {
                pe->flag = -1;
            }
            pe--;
            pi--;
        } while (pe >= &o->ents[0]);
    } else {
        pe = &o->ents[3];
        do {
            pe->flag = -1;
            pe--;
        } while (pe >= &o->ents[0]);
    }

    end = &o->ents[3];
    pf = &o->ents[3];
    do {
        if (pf->flag >= 0) {
            if (pf->x <= o->unk4F4 || pf->x >= o->unk4FC || pf->y <= o->unk4F8 || pf->y >= o->unk500) {
                pf->flag |= 1;
            }
        }
        pf--;
    } while (pf >= &o->ents[0]);

    pg = &o->ents[0];
    do {
        if (pg->flag == 0) {
            pf = pg + 1;
            do {
                f2 = pf->flag;
                if ((s8)f2 == 0 && pg->x == pf->x && pg->y == pf->y) {
                    pf->flag = f2 | 2;
                }
                pf++;
            } while (pf <= end);
        }
        pg++;
    } while (pg < end);

    pe = &o->ents[3];
    o->unk10C = 0;
    do {
        if (pe->flag == 0) {
            o->unk10C = o->unk10C + 1;
        }
        pe--;
    } while (pe >= &o->ents[0]);

    if (!(o->unk54 <= lbl_8059ED54)) {
        k = o->unk5E;
        if (k == 2 || k == -2) {
            if (o->unk10C >= 2) {
                r30 = fn_802263D4(o);
                if (r30 != 0) goto done;
            }
            if (o->unk10C >= 1) {
                r30 = fn_802267B0(o);
                if (r30 != 0) goto done;
            }
        } else if (k == 1 || k == -1) {
            if (o->unk10C >= 2) {
                r30 = fn_802261EC(o);
                if (r30 != 0) goto done;
            }
            if (o->unk10C >= 1) {
                r30 = fn_802267B0(o);
                if (r30 != 0) goto done;
            }
        } else {
            if (o->unk10C >= 2) {
                r30 = fn_802261EC(o);
                if (r30 != 0) goto done;
            }
            if (o->unk10C == 1) {
                r30 = fn_802265FC(o);
                if (r30 != 0) goto done;
            }
        }
    }
    r30 = 0;

done:
    if (r30 != 0) {
        dx = o->unk100 - o->unkF4;
        dy = o->unk104 - o->unkF8;
        len = (f32)fn_80400D94(dx * dx + dy * dy);
        t = lbl_805A39F8 / len;
        o->unk490 = len;
        dx *= t;
        dy *= t;
        o->unk494 = dx;
        b = o->unk510;
        a = b * t;
        t = o->unkB0;
        b = o->unkB4;
        c = t * dx + b * dy;
        o->unk49C = a;
        d = b * dx - t * dy;
        o->unk498 = dy;
        o->unk4B0 = c;
        o->unk4B4 = d;
        if (o->unk4C8 == 0) {
            if (c * o->unk4B8 + d * o->unk4BC <= lbl_8059ED50) {
                o->unk108 = 1;
                o->unkFC = 1;
                r30 = 0;
            }
        }
        if ((o->unk5E & 0xFF) == 2 && (s8)r30 == 2) {
            if (o->unk4CA == 0xC8) {
                o->unk4A0 = o->unk490;
            } else {
                o->unk4CA = o->unk4CA + 1;
            }
        } else {
            o->unk4CA = 0;
        }
    } else {
        o->unk4CA = 0;
    }
    fn_80226924(o, r30);
}
