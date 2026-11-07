#include <revolution/BASE/PPCArch.h>
#pragma force_active on

typedef struct Ctx {
    char pad[0x698];
    u16 field698;
    char pad69a[2];
    u8 *ptr;
    u32 field6a0;
    u32 cnt;
    u8 field6a8;
    u8 rst;
    u16 interval;
    u16 nMCU;
} Ctx;

extern int lbl_805A0D40;
extern Ctx *lbl_805A0D44;
extern u8 *lbl_805A0D48;
extern void *lbl_80532000[6];

extern void fn_801D77A0(u32, u32);
extern u8 fn_8025C3F8(void);
extern u8 fn_8025C52C(void);
extern u8 fn_8025C640(void);
extern u8 fn_8025C9D8(void);
extern void fn_8025CFE4(void *, void *, void *);

int fn_8025C138(u8 *input, void *a, void *b, void *c, void *work)
{
    int done;
    u8 marker, result;
    u8 *p;
    u8 *buf;

    if (!input)
        goto err25;
    if (!a || !b || !c)
        goto err27;
    if (!work)
        goto err26;
    if (!(PPCMfhid2() & 0x10000000))
        goto err28;
    if (!lbl_805A0D40)
        goto err29;

    lbl_805A0D44 = (Ctx *)(((u32)work + 31) & ~31);
    lbl_805A0D48 = (u8 *)lbl_805A0D44 + 0x6bc;
    fn_801D77A0((u32)lbl_805A0D44, 0x6bc);

    lbl_805A0D44->cnt = 0x21;
    lbl_805A0D44->field698 = 0;
    lbl_805A0D44->ptr = input;
    done = 0;

    do {
        if (*lbl_805A0D44->ptr++ != 0xff)
            goto err3;

        while (*lbl_805A0D44->ptr == 0xff)
            lbl_805A0D44->ptr++;

        marker = *lbl_805A0D44->ptr++;
        if (marker <= 0xd7) {
            if (marker == 0xc4) {
                result = fn_8025C9D8();
                if (result)
                    goto errresult;
            } else if (marker == 0xc0) {
                result = fn_8025C3F8();
                if (result)
                    goto errresult;
            } else {
                goto err11;
            }
        } else if (marker >= 0xd8 && marker <= 0xdf) {
            if (marker == 0xdd) {
                lbl_805A0D44->rst = 1;
                lbl_805A0D44->ptr += 2;
                lbl_805A0D44->interval =
                    (lbl_805A0D44->ptr[0] << 8) |
                    lbl_805A0D44->ptr[1];
                lbl_805A0D44->ptr += 2;
                lbl_805A0D44->nMCU = lbl_805A0D44->interval;
            } else if (marker == 0xdb) {
                result = fn_8025C640();
                if (result)
                    goto errresult;
            } else if (marker == 0xda) {
                result = fn_8025C52C();
                if (result)
                    goto errresult;
                done = 1;
            } else if (marker == 0xd8) {
            } else {
                goto err11;
            }
        } else if (marker >= 0xe0) {
            if ((marker >= 0xe0 && marker <= 0xef) || marker == 0xfe) {
                p = lbl_805A0D44->ptr;
                lbl_805A0D44->ptr = p + ((p[0] << 8) | p[1]);
            } else {
                goto err11;
            }
        }
    } while (!done);

    buf = (u8 *)(((u32)lbl_805A0D48 + 31) & ~31);
    lbl_80532000[0] = buf;
    lbl_80532000[1] = buf + 0x80;
    lbl_80532000[2] = buf + 0x100;
    lbl_80532000[3] = buf + 0x180;
    lbl_80532000[4] = buf + 0x200;
    lbl_80532000[5] = buf + 0x280;
    fn_8025CFE4(a, b, c);
    return 0;

err25:
    return 25;
err27:
    return 27;
err26:
    return 26;
err11:
    return 11;
err3:
    return 3;
errresult:
    return result;
err28:
    return 28;
err29:
    return 29;
}
