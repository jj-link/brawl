#include <types.h>
#pragma force_active on

extern s32 fn_803B2088(u8, s32, s32);
extern s32 fn_803B2100(u8 *, s32, u8);
extern s32 fn_803B2BD8(u8 *, u8 *);
extern s32 fn_803BE78C(u8 *, u8 *, s32);
extern void fn_803BE914(u8 *, u8 *, u8);
extern void fn_803BEB70(u8 *, u16 *, u8);
extern s32 fn_803BEF50(u8 *, u16 *);

static inline u32 swap16(u32 v) {
    return ((v >> 8) & 0xFF) | ((v << 8) & 0xFF00);
}

s32 fn_803B2240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 kind;
    u8 attr;
    u16 wide[8];
    u8 buf[12];
    s32 result;
    s32 len;
    s32 quot;
    s32 rem;
    u8 sum;
    u16 i;

    attr = arg1[0x57];
    kind = attr & 0xF;

    if ((attr & 0xF) == 0xF) {
        result = 1;
    } else if (fn_803B2088(attr, arg3, arg4) == 0) {
        result = 1;
    } else {
        if (attr & 8) {
            arg0[0x20A] = 0;
            *(u16 *)arg0 = 0;
        }
        fn_803BE914(arg0 + 0x20E, arg1 + 0x4C, arg1[0x57]);
        if ((s32)arg0[0x20E] == 5) {
            ((s8 *)arg0)[0x20E] = -0x1B;
        }
        result = fn_803B2100(arg0, arg2, attr);
        if (result == 1) {
            *arg5 += 1;
        }
    }

    if (result == 1) {
        if (kind == 0xF) {
            if (fn_803B2BD8(arg0, arg1 + 0x4C) != 0) {
                arg0[0x20A] = 0;
                *(u16 *)arg0 = 0;
            }
        } else {
            arg0[0x20A] = 0;
            *(u16 *)arg0 = 0;
        }
        return -1;
    }

    if (arg0[0x20A] == 0 && (arg1[0x58] & 0x18)) {
        fn_803BEB70(arg0 + 0x20E, wide, arg1[0x58]);
        len = fn_803BEF50(arg0, wide);
        quot = len / 13;
        rem = len % 13;
        arg0[0x20A] = (u8)(quot + (rem != 0));
        fn_803BE78C(buf, arg0 + 0x20E, 0);
        sum = 0;
        for (i = 0; i < 11; i++) {
            sum = (u8)(buf[i] + (sum >> 1) + ((sum & 1) ? 0x80 : 0));
        }
        arg0[0x20C] = sum;
        arg0[0x20B] = 1;
    }

    attr = arg1[0x57];
    arg0[0x21C] = attr;
    arg0[0x21B] = arg1[0x58];
    arg0[0x21D] = arg1[0x59];
    *(u16 *)(arg0 + 0x21E) = swap16(*(u16 *)(arg1 + 0x5A));
    *(u16 *)(arg0 + 0x220) = swap16(*(u16 *)(arg1 + 0x5C));
    *(u16 *)(arg0 + 0x222) = swap16(*(u16 *)(arg1 + 0x5E));
    *(u16 *)(arg0 + 0x224) = swap16(*(u16 *)(arg1 + 0x62));
    *(u16 *)(arg0 + 0x226) = swap16(*(u16 *)(arg1 + 0x64));
    {
        u32 w = *(u32 *)(arg1 + 0x68);
        *(u32 *)(arg0 + 0x228) = (w >> 24) | ((w >> 8) & 0xFF00) | ((w << 8) & 0xFF0000) | (w << 24);
    }
    {
        *(u32 *)(arg0 + 0x234) = swap16(*(u16 *)(arg1 + 0x66)) | (swap16(*(u16 *)(arg1 + 0x60)) << 16);
    }
    *(u32 *)(arg0 + 0x238) = *(u32 *)(arg1 + 0x44);
    *(u16 *)(arg0 + 0x23C) = *(u16 *)(arg1 + 0x48);
    if ((attr & 0x10) && *(u32 *)(arg0 + 0x234) == 0)
        *(u32 *)(arg0 + 0x234) = 1;
    return 0;
}
