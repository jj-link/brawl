#include <types.h>
#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Msg {
    u32 type;
    s8 a;
    char pad_a[3];
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s16 f;
    s16 g;
    s32 h;
    s32 i;
    s32 j;
    s32 k;
    s32 cb;
} Msg;

typedef struct State {
    char pad0[0x160];
    s8 head1;
    s8 tail1;
    char pad1[2];
    Msg *buf1;
    s32 size1;
    char pad2[0x5EC - 0x16C];
    s8 head2;
    s8 tail2;
    char pad3[2];
    Msg *buf2;
    s32 size2;
    char pad4[0x840 - 0x5F8];
    s32 f840;
    char pad5[0x8BC - 0x844];
    s32 f8BC;
    char pad6[0x8D0 - 0x8C0];
    s32 f8D0;
    char pad7[0x8D8 - 0x8D4];
    s32 f8D8;
} State;

extern State *lbl_804F6810[];
extern u8 lbl_805A0C58;
extern u8 lbl_805A0C5C;
extern s32 lbl_805A0C60;
extern u8 lbl_805A0C54;
extern u16 lbl_805A0C52;
extern u16 lbl_805A0C56;
extern u8 lbl_805A0C64;
extern u8 lbl_805A0C66;
extern u8 lbl_805A0C71;
extern u8 lbl_805A0C72;
extern s32 lbl_805A0C74;
extern u8 lbl_805A0C78;
extern u8 lbl_805A0C79;
extern char lbl_8047C6F0[];
extern char lbl_8047C718[];
extern char lbl_804FBD58[];

extern void fn_80219984(void);
extern void fn_80219DF8(void);
extern s32 fn_8022BB2C(void);
extern s32 fn_8022C034(s32 arg);
extern s32 fn_8022BFD8(s32 arg);
extern s32 fn_80217018(s32 index, Msg *msg);
extern void fn_802171F4(s32 index);
extern void fn_80217FB0(s32 index);
extern s32 fn_8021DA28(s32 index, Msg *msg);
extern s32 fn_8022550C(const char *format, ...);
extern void fn_8022BEEC(s8 val);
extern void fn_801D76BC(void *a, s32 b);
extern s32 fn_8020E18C(void);
extern s32 fn_8020FDF4(void *a);
extern void fn_8020F5FC(s32 val);
extern u8 fn_8020FE18(void);
extern u8 fn_8020FE80(void);
extern u8 fn_8020FEDC(void);
extern s32 fn_8020FF30(void);
extern void fn_802375AC(void);

void fn_80218134(void)
{
    s32 val1;
    s32 val10;
    s32 active;
    State *st;
    s32 first_en;
    s32 en;
    u8 *p58;
    State **pst;
    u8 *p5C;
    s32 i;
    s32 ok;
    s8 cnt;
    s32 en2;
    s32 ok2;
    s32 mode;
    Msg copy;
    Msg local;
    Msg copy2;
    Msg local2;
    Msg m2;
    Msg m;
    u8 t;
    s32 r4;

    val1 = 1;
    val10 = 0x10;
    active = 0;

    mode = fn_8022BB2C();
    if (mode != 3) {
        if (mode == 2) {
            if (lbl_805A0C60 == 0) {
                lbl_805A0C60 = 1;
                fn_8022C034((s32)fn_80219984);
                fn_8022BFD8((s32)fn_80219DF8);
            }
        }
    } else {
        i = 0;
        pst = lbl_804F6810;
        p58 = &lbl_805A0C58;
        p5C = &lbl_805A0C5C;
        do {
            ok = active;
            if (*p58 == 5) {
                s32 en;
                st = *pst;
                if (st->f8D8 == 0)
                    goto first_failed;
                first_en = OSDisableInterrupts();
                en = OSDisableInterrupts();
                cnt = st->tail2 - st->head2;
                if (cnt < 0) {
                    cnt += st->size2;
                }
                OSRestoreInterrupts(en);
                if (cnt == 0) {
                    OSRestoreInterrupts(first_en);
                    ok2 = 0;
                } else {
                    memcpy(&local, st->buf2 + st->head2, 0x30);
                    OSRestoreInterrupts(first_en);
                    ok2 = 1;
                }
                if (ok2 == 0 || (local.type != 0x12 && st->f840 == 0))
                    goto first_failed;
                copy = local;
                if (fn_80217018(i, &copy) != 0)
                    goto first_failed;
                en = OSDisableInterrupts();
                en2 = OSDisableInterrupts();
                cnt = st->tail2 - st->head2;
                if (cnt < 0) {
                    cnt += st->size2;
                }
                OSRestoreInterrupts(en2);
                if (cnt == 0) {
                    OSRestoreInterrupts(en);
                } else {
                    memset(st->buf2 + st->head2, 0, 0x30);
                    st->head2 = (st->head2 == st->size2 - 1) ? 0 : st->head2 + 1;
                    OSRestoreInterrupts(en);
                }
                ok = 1;
                goto first_done;
            first_failed:
                ok = 0;
            first_done:
                if (ok != 0) {
                    *p58 = active;
                }
            }
            if (ok == 0) {
                st = *pst;
                if (st->f8D8 == 0)
                    goto second_failed;
                en = OSDisableInterrupts();
                en2 = OSDisableInterrupts();
                cnt = st->tail1 - st->head1;
                if (cnt < 0) {
                    cnt += st->size1;
                }
                OSRestoreInterrupts(en2);
                if (cnt == 0) {
                    OSRestoreInterrupts(en);
                    ok2 = 0;
                } else {
                    memcpy(&local2, st->buf1 + st->head1, 0x30);
                    OSRestoreInterrupts(en);
                    ok2 = 1;
                }
                if (ok2 == 0)
                    goto second_failed;
                copy2 = local2;
                if (fn_80217018(i, &copy2) != 0)
                    goto second_failed;
                en = OSDisableInterrupts();
                en2 = OSDisableInterrupts();
                cnt = st->tail1 - st->head1;
                if (cnt < 0) {
                    cnt += st->size1;
                }
                OSRestoreInterrupts(en2);
                if (cnt == 0) {
                    OSRestoreInterrupts(en);
                } else {
                    memset(st->buf1 + st->head1, 0, 0x30);
                    st->head1 = (st->head1 == st->size1 - 1) ? 0 : st->head1 + 1;
                    OSRestoreInterrupts(en);
                }
                ok2 = 1;
                goto second_done;
            second_failed:
                ok2 = 0;
            second_done:
                ok |= ok2;
            }

            {
                State *st = *pst;
                if (st->f8BC != -1) {
                    if (ok == 1)
                        goto reset_count;
                    en = OSDisableInterrupts();
                    cnt = st->tail1 - st->head1;
                    if (cnt < 0) {
                        cnt += st->size1;
                    }
                    OSRestoreInterrupts(en);
                    if (cnt > 0) {
                    reset_count:
                        (*pst)->f8D0 = active;
                    } else if (*p5C == 5) {
                        m.type = val10;
                        m.g = val1;
                        m.a = active;
                        m.cb = active;
                        (*pst)->f8D0 = active;
                        m2 = m;
                        fn_8021DA28(i, &m2);
                    }
                    *p5C = ((*pst)->f8D0 != 0) ? *p5C + 1 : 0;
                }
            }

            if (lbl_805A0C54 == 5) {
                fn_80217FB0(i);
            }
            if (lbl_805A0C52 == 0xA) {
                fn_802171F4(i);
            }
            t = *p58;
            *p58 = (t == 5) ? t : t + 1;
            i += 1;
            p58 += 1;
            pst += 1;
            p5C += 1;
        } while (i < 4);

        if (lbl_805A0C56 == 0xEA60) {
            u8 *pv = (u8 *)0x800031A2;
            fn_801D76BC(pv, 1);
            fn_8022550C(lbl_8047C6F0);
            if ((s8)lbl_805A0C64 != *pv) {
                en = OSDisableInterrupts();
                lbl_805A0C64 = *pv;
                OSRestoreInterrupts(en);
                fn_8022550C(lbl_8047C718, *pv);
                fn_8022BEEC((s8)lbl_805A0C64);
            }
        }

        lbl_805A0C52 = (lbl_805A0C52 == 0xA) ? 0 : lbl_805A0C52 + 1;
        lbl_805A0C54 = (lbl_805A0C54 == 5) ? 0 : lbl_805A0C54 + 1;
        lbl_805A0C56 = (lbl_805A0C56 == 0xEA60) ? 0 : lbl_805A0C56 + 1;

        if (lbl_805A0C71 != 0 && fn_8020E18C() == 0 && fn_8020FDF4(lbl_804FBD58) == 1) {
            fn_8020F5FC(0);
            lbl_805A0C71 = 0;
        }
        if (lbl_805A0C66 != 0 && fn_8020E18C() == 0) {
            {
                u32 value = fn_8020FE18();
                if (value < 1) {
                    value = 1;
                }
                if (value > 5) {
                    value = 5;
                }
                lbl_805A0C79 = value;
            }
            t = fn_8020FEDC();
            lbl_805A0C78 = (t == 1);
            t = fn_8020FE80();
            lbl_805A0C74 = (t == 1);
            {
                s32 raw = fn_8020FF30();
                r4 = raw;
                if ((u8)raw == 0) {
                    r4 = 0;
                }
                if ((u8)raw >= 0x7F) {
                    r4 = 0x7F;
                }
                lbl_805A0C72 = r4;
            }
            lbl_805A0C66 = 0;
        }
        fn_802375AC();
    }
}
