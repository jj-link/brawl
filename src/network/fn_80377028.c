#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct Cfg {
    char pad[0x40];
    s32 unk40;
    s32 unk44;
};

struct State {
    s32 unk0;
    u16 unk4;
    u8 pad6[2];
    struct Cfg *unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x50 - 0x18];
    u8 unk50[8];
    s32 unk58;
    s32 unk5C;
    void *unk60;
    u16 unk64;
    u16 unk66;
};

struct Rec {
    s32 a;
    s32 b;
    u16 c;
    u32 d;
};

extern s16 lbl_8059F980;
extern s32 fn_803737D8(void *);
extern void fn_803737E8(void *, u8);
extern void fn_80373800(void *, u16);
extern void fn_8037382C(void *, void *, s32);
extern s32 fn_80373AA0(struct State *, s32, s32, s32);
extern s32 fn_80373C54(struct State *, s32);
extern void fn_80374778(struct State *);
extern s32 fn_803783C4(struct Cfg *, s32, u16, u8 *, s32);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, s32, u32);
extern s32 fn_8035A590(void *);
extern void fn_8035A5C8(void *, void *);
extern u32 fn_8035D728(void);

static inline s32 fn_send_inl(struct State *arg0, u8 *buf)
{
    s32 off;
    u16 cnt;
    s32 tmp;
    struct Cfg *c;
    s16 sp;
    s32 r;

    c = arg0->unk8;
    off = 0;
    cnt = arg0->unk4;
    tmp = arg0->unk0;
    if (c->unk40 == 2) {
        sp = 3;
        memcpy(buf, &sp, 2);
        off = 2;
    }
    memcpy(buf + off, &lbl_8059F980, 2);
    buf[off += 2] = 0x68;
    r = fn_803783C4(c, tmp, cnt, buf, off + 1);
    if (((u32)(-r | r) >> 31) == 0) {
        return 0;
    }
    if (arg0->unkC < 5) {
        if (arg0->unk10 != 0) {
            fn_80374778(arg0);
            if (fn_80373AA0(arg0, 1, 0, 0) == 0) {
                return 0;
            }
        } else {
            if (arg0->unkC == 4) {
                arg0->unk14 = 1;
            }
            fn_80374778(arg0);
        }
    } else if (arg0->unkC != 7) {
        fn_80374778(arg0);
        if (fn_80373C54(arg0, 4) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 fn_80377028(struct State *arg0, s32 arg1, s32 arg2, s32 *arg3)
{
    s16 spC;
    u8 sp18[8];
    u8 sp10[8];
    struct Rec sp20;
    struct Cfg *cfg;
    s32 idx;
    s32 eq;
    u16 seq;

    cfg = arg0->unk8;
    spC = arg2 - cfg->unk44;
    if (fn_803737D8(arg0->unk50) < arg2) {
        if (fn_send_inl(arg0, sp18) == 0) {
            return 0;
        }
        *arg3 = 1;
        return 1;
    }

    seq = arg0->unk64;
    memset(&sp20, 0, 0x10);
    sp20.a = arg0->unk58;
    sp20.b = arg2;
    sp20.c = seq;
    sp20.d = fn_8035D728();
    idx = fn_8035A590(arg0->unk60);
    fn_8035A5C8(arg0->unk60, &sp20);
    eq = (fn_8035A590(arg0->unk60) - (idx + 1)) == 0;
    if (!eq) {
        if (fn_send_inl(arg0, sp10) == 0) {
            return 0;
        }
        *arg3 = 1;
        return 1;
    }

    cfg = arg0->unk8;
    if (cfg->unk40 == 2) {
        fn_8037382C(arg0->unk50, &spC, cfg->unk44);
    }
    fn_8037382C(arg0->unk50, &lbl_8059F980, 2);
    fn_803737E8(arg0->unk50, arg1);
    seq = arg0->unk64;
    arg0->unk64 = seq + 1;
    fn_80373800(arg0->unk50, seq);
    fn_80373800(arg0->unk50, arg0->unk66);
    *arg3 = 0;
    return 1;
}
