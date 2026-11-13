#pragma force_active on
#include <types.h>

typedef struct NetCtx {
    u8 pad_00[0x24];
    s32 unk24;
    s32 unk28;
    u8 unk2C;
    u8 unk2D;
    u8 pad_2E[0x90 - 0x2E];
    void (*unk90)(s32, s32, s32, u8, s32, s32);
    s32 unk94;
    u8 pad_98[0x36D - 0x98];
    u8 unk36D;
    u8 unk36E;
    u8 pad_36F;
    void *unk370;
    u8 unk374;
    u8 unk375;
    u8 unk376;
    u8 unk377;
    u8 unk378;
    u8 pad_379[3];
    u32 unk37C;
    u8 pad_380[0x398 - 0x380];
    u32 unk398[32];
    u16 unk418[40];
    u32 unk468[43];
    s32 unk514;
    u32 pad_518[(0x648 - 0x518) / 4];
    u8 unk648[32];
    u32 unk668;
    u8 pad_66C[0x7FC - 0x66C];
    u32 unk7FC;
    u8 pad_800[0x11D8 - 0x800];
    u8 unk11D8;
} NetCtx;

static inline u8 get_375(NetCtx *ctx) {
    return ctx->unk375;
}

extern NetCtx *lbl_805A0F88;
extern char lbl_80489E48[];
extern void *lbl_80533730[32];

extern s32 fn_80342544(void);
extern void fn_80335638(s32, const char *, ...);
extern u8 *fn_80374C28(void *);
extern s32 fn_80337248(s32);
extern void fn_8033C0D4(void);
extern void fn_80341454(void);
extern s32 fn_80341868(s32, s32, s32);
extern void fn_80341DDC(s32);
extern s32 fn_80341E20(s32, s32);
extern s32 fn_80342244(u8 **);
extern void fn_80342328(s32);
extern void fn_8033524C(s32, s32);
extern void fn_8034EAB8(s32);
extern void fn_80379148(void *);

void fn_8033BA40(s32 arg0, s32 arg1) {
    char *base;
    u8 r29;
    s32 r28 = 0;
    s32 r27;
    s32 r26 = 0;
    u8 r25;
    s32 r24;
    u8 *r31;
    u8 *sp10;
    u32 mask;
    u32 masked;
    s32 cnt;
    s32 k;
    u8 *p;
    s32 i;
    u8 r27_3;
    u8 t;
    u8 v;
    u8 *q;
    NetCtx *c;

    base = lbl_80489E48;
    if (fn_80342544() != 0) {
        fn_80335638(8, base + 0xA90);
        return;
    }

    switch (arg1) {
    case 0:
    case 1:
        r24 = 0;
        r27 = 0;
        break;
    case 2:
    case 3:
        r24 = 6;
        r27 = -0x1DB0;
        break;
    case 4:
        r24 = 9;
        r27 = -0x1DB1;
        break;
    }

    fn_80335638(4, base + 0xACC, arg1);
    if (r24 == 0) {
        r31 = fn_80374C28((void *)arg0);
        if (r31 == 0) {
            return;
        }

        r29 = r31[1];
        mask = 1 << r29;
        masked = lbl_805A0F88->unk668 & mask;
        r25 = masked != 0;
        fn_8034EAB8(r29);
        fn_80335638(4, base + 0xAF0, r29, r25);
        lbl_805A0F88->unk37C &= ~mask;

        if (lbl_805A0F88->unk375 == 2 && arg1 == 0) {
            goto flag_set;
        }
        if (((u8 *)lbl_805A0F88)[0x375] == 3 &&
            r29 == lbl_805A0F88->unk648[0]) {
            goto flag_set;
        }
        goto flag_done;

    flag_set:
        r26 = 1;
        fn_80335638(0x200004, base + 0xB0C);

    flag_done:
        cnt = fn_80342244(&sp10);
        p = sp10;
        for (k = 0; k < cnt; p++, k++) {
            if (r29 == *p) {
                break;
            }
        }

        if (k == cnt) {
            r28 = 0;
        } else {
            r28 = fn_80341E20(k, cnt);
        }

        lbl_80533730[r31[0]] = 0;
        lbl_805A0F88->unk36D = (u8)(lbl_805A0F88->unk36D - 1);
        lbl_805A0F88->unk374 = (u8)(lbl_805A0F88->unk374 - 1);
    }

    lbl_805A0F88->unk7FC = 0;
    for (i = 0; i < lbl_805A0F88->unk36E + 1; i++) {
        lbl_805A0F88->unk7FC |= 1 << lbl_805A0F88->unk648[i];
    }

    if (lbl_805A0F88->unk2D == 0 &&
        lbl_805A0F88->unk24 == 6 && r25 == 0) {
        if (lbl_805A0F88->unk375 == 2 && r24 == 0) {
            fn_80342328(-1);
            fn_80341DDC(r28);
        }
        fn_80335638(4, base + 0xB30);
        return;
    }

    if (fn_80341868(r24, r27, r28) != 0) {
        fn_80335638(4, base + 0xB54);
        return;
    }

    if (r24 != 0) {
        fn_8033524C(r24, r27 - 0x10000 - 0x3880);
        return;
    }

    c = lbl_805A0F88;
    if (c->unk2D == 0 &&
        (get_375(c) == 2 || ((const NetCtx *)lbl_805A0F88)->unk375 == 3)) {
        c = lbl_805A0F88;
        t = c->unk36D;
        if (c->unk468[t + 2] != 0) {
            q = c->unk648;
            q[t + 1] = q[t + 2];
            fn_80341E20(lbl_805A0F88->unk36D + 1,
                        lbl_805A0F88->unk36D + 3);
        }
    }

    if (lbl_805A0F88->unk375 == 2) {
        if (lbl_805A0F88->unk2D == 0) {
            fn_80342328(-1);
        } else if (lbl_805A0F88->unk36D == 0) {
            fn_80342328(1);
        }
    } else if (lbl_805A0F88->unk36D == 0) {
        fn_80342328(1);
    }

    for (i = 0; i < lbl_805A0F88->unk36D + 1; i++) {
        fn_80335638(4, base + 0xB74, i, lbl_805A0F88->unk648[i], i,
                    lbl_805A0F88->unk468[i], i, lbl_805A0F88->unk398[i],
                    lbl_805A0F88->unk418[i]);
    }

    if (lbl_805A0F88 != 0) {
        r27_3 = lbl_805A0F88->unk2C;
    } else {
        r27_3 = 0;
    }
    fn_80335638(4, base + 0xBB0);

    for (i = 0; i < lbl_805A0F88->unk36D + 1; i++) {
        v = lbl_805A0F88->unk648[i];
        if (r27_3 == v) {
            q = (u8 *)lbl_805A0F88 + 0x82C;
        } else {
            q = (u8 *)lbl_805A0F88 + ((v * 4) & 0x3FC) + 0x834;
        }
        fn_80335638(4, base + 0xBC0, i, v, q[0], q[1], q[2], q[3]);
    }

    if (lbl_805A0F88->unk376 == 0) {
        goto set_378;
    }
    if (((const NetCtx *)lbl_805A0F88)->unk376 == 1) {
        goto set_378;
    }
    goto no_378;

set_378:
    lbl_805A0F88->unk378 = lbl_805A0F88->unk374;
    fn_80379148(lbl_805A0F88->unk370);

no_378:
    c = lbl_805A0F88;
    if (c->unk90 != 0 && r25 != 0) {
        lbl_805A0F88->unk90(r24, arg1 == 0 ? 1 : 0, r26, r29,
                            fn_80337248(r28), c->unk94);
    }

    if (lbl_805A0F88->unk2D != 0 ||
        (u32)lbl_805A0F88->unk375 != 2) {
        if ((u32)lbl_805A0F88->unk375 == 3 && r26 != 0 &&
            (arg1 == 1 || lbl_805A0F88->unk11D8 != 0)) {
            if (lbl_805A0F88->unk36D == 0) {
                lbl_805A0F88->unk514 = 11;
            } else {
                lbl_805A0F88->unk514 = 9;
            }
            return;
        }

        if (lbl_805A0F88->unk36D == 0) {
            if (lbl_805A0F88->unk2D != 0) {
                fn_8033C0D4();
                fn_80341454();
                lbl_805A0F88->unk28 = lbl_805A0F88->unk24;
                lbl_805A0F88->unk24 = 3;
                lbl_805A0F88->unk377 = 0;
            } else {
                lbl_805A0F88->unk514 = 11;
            }
        }
    }
}
