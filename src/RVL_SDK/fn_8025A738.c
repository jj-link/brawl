#include <types.h>
#include <string.h>
#pragma force_active on

extern void fn_8025B344(u8 *, u16, s32, s32);
extern u8 *fn_8025B7D0(u8 *, u32, u16 *);
extern u8 *fn_80257938(u32);
extern u8 *fn_80257994(u8 *, u16, u16);
extern u8 *fn_8025B1F0(u8 *, u8 *);
extern u8 *fn_8022EFF8(s32);
extern void fn_802319E4(u32, const char *);
extern void fn_8024ABC4(u16, u8 *, s32);
extern u8 lbl_8052D9C0[];
extern char lbl_80485164[];

void fn_8025A738(u8 *arg0, u16 arg1, u32 arg2, u8 *arg3, u8 *arg4)
{
    u32 key;
    u16 tbl[32];
    u8 *p;
    u16 *ent;
    u16 r30;
    u8 *ctx2;
    u8 *d;
    u8 *r29;
    u8 *r31;
    u8 *r28;
    u8 *pkt;
    u32 lim;
    s32 x;
    s32 len;
    u8 *ctx;
    u16 i;
    u16 doff;
    u16 v;
    u16 rem;

    key = ((u32)arg3[0] << 24) + ((u32)arg3[1] << 16) + (arg3[3] + ((u32)arg3[2] << 8));
    if (arg3 + 4 > arg4) {
        fn_8025B344(arg0, arg1, 2, 0);
        return;
    }
    r30 = (u16)((arg3[4] << 8) + arg3[5]);
    if ((s32)r30 > (s32)*(u16 *)(arg0 + 0x20) - 10) {
        r30 = (u16)((s32)*(u16 *)(arg0 + 0x20) - 10);
    }
    p = fn_8025B7D0(arg3 + 6, arg2, tbl);
    if (p == 0 || tbl[0] == 0 || (u32)p > (u32)arg4) {
        fn_8025B344(arg0, arg1, 3, 0);
        return;
    }
    ctx = fn_80257938(key);
    if (ctx == 0) {
        fn_8025B344(arg0, arg1, 2, 0);
        return;
    }
    if (p[0] != 0) {
        if (p[0] != 2) {
            fn_8025B344(arg0, arg1, 5, 0);
            return;
        }
        v = (u16)((p[1] << 8) + p[2]);
        if (v != *(u16 *)(arg0 + 0x476)) {
            fn_8025B344(arg0, arg1, 5, 0);
            return;
        }
    } else {
        *(u16 *)(arg0 + 0x476) = 0;
        d = arg0 + 0x29;
        for (i = 0; i < tbl[0]; i++) {
            ent = &tbl[i * 2];
            ctx2 = fn_80257994(ctx, ent[1], ent[2]);
            if (ctx2 != 0) {
                lim = (u32)((s32)(u16)(0x3E8 - (u16)(d - (arg0 + 0x26))) - 6);
                if (*(u32 *)ctx2 > lim) {
                    break;
                }
                d = fn_8025B1F0(d, ctx2);
                if (ent[1] != ent[2]) {
                    i--;
                    ent[1] = (u16)(*(u16 *)(ctx2 + 8) + 1);
                }
            }
        }
        doff = (u16)(d - (arg0 + 0x26));
        *(u16 *)(arg0 + 0x24) = doff;
        if (doff > 0xFF) {
            arg0[0x26] = 0x36;
            arg0[0x27] = (u8)((*(u16 *)(arg0 + 0x24) - 3) >> 8);
            arg0[0x28] = (u8)(*(u16 *)(arg0 + 0x24) - 3);
        } else {
            *(u16 *)(arg0 + 0x476) = 1;
            arg0[0x27] = 0x35;
            arg0[0x28] = (u8)(doff - 3);
            *(u16 *)(arg0 + 0x24) = (u16)(doff - 1);
        }
    }

    pkt = fn_8022EFF8(2);
    if (pkt == 0) {
        if (lbl_8052D9C0[0x4630] >= 1) {
            fn_802319E4(0xA0000, lbl_80485164);
        }
        return;
    }
    *(u16 *)(pkt + 4) = 9;
    r29 = pkt + 0x11;
    r29[0] = 5;
    r31 = r29 + 3;
    r28 = r31;
    r29[1] = (u8)(arg1 >> 8);
    r29[2] = (u8)arg1;
    v = *(u16 *)(arg0 + 0x24);
    if (v <= r30) {
        r30 = v;
    }
    r31[2] = (u8)(r30 >> 8);
    r31[3] = (u8)r30;
    r31 += 4;
    memcpy(r31, arg0 + *(u16 *)(arg0 + 0x476) + 0x26, r30);
    r31 += r30;
    rem = *(u16 *)(arg0 + 0x476);
    *(u16 *)(arg0 + 0x24) -= r30;
    *(u16 *)(arg0 + 0x476) = rem + r30;
    if (*(u16 *)(arg0 + 0x24) != 0) {
        r31[0] = 2;
        r31[1] = (u8)(*(u16 *)(arg0 + 0x476) >> 8);
        r31[2] = (u8)*(u16 *)(arg0 + 0x476);
        r31 += 3;
    } else {
        r31[0] = 0;
        r31 += 1;
    }
    len = (s32)(r31 - r28) - 2;
    r28[0] = (u8)((u16)len >> 8);
    r28[1] = (u8)len;
    *(u16 *)(pkt + 2) = (u16)(r31 - r29);
    fn_8024ABC4(*(u16 *)(arg0 + 0x22), pkt, len);
}
