#include <types.h>
#pragma force_active on

typedef struct {
    u16 a;
    u16 b;
    s16* c;
    s16* d;
    s16* e;
} Q;

extern s32 fn_8020533C(Q* p, u8* src, s32 len, u16* dist, s32 window);
extern void fn_80205474(Q* p, u8* src);

static u32 bswap32(u32 x) {
    return (x >> 24) | ((x >> 8) & 0xFF00) | ((x << 8) & 0xFF0000) | (x << 24);
}

static void LZInitTable(Q* info, s16* work) {
    u16 i;
    info->c = work;
    info->d = work + 0x1000;
    info->e = work + 0x1100;
    for (i = 0; i < 0x100; i++) {
        info->d[i] = -1;
        info->e[i] = -1;
    }
    info->a = 0;
    info->b = 0;
}

s32 fn_80204FC8(u8* s, u32 rem, u8* d, s16* work, s32 flg) {
    Q q;
    u16 dist;
    u8* sp;
    u32 ci;
    u32 outCnt;
    u8 fbyte;
    u8* fptr;
    u32 bit;
    u32 limit;
    u32 window;
    u32 mlen;
    u32 code;
    u8 pad;

    window = 0x12;
    if (flg != 0) {
        window = 0x10110;
    }
    if (rem < 0x1000000) {
        outCnt = 4;
        *(u32*)d = bswap32((rem << 8) | 0x10 | (flg ? 1 : 0));
        d += 4;
    } else {
        outCnt = 8;
        *(u32*)d = bswap32(0x10 | (flg ? 1 : 0));
        *(u32*)(d + 4) = bswap32(rem);
        d += 8;
    }
    limit = rem;
    LZInitTable(&q, work);
    while (rem != 0) {
        fptr = d;
        fbyte = 0;
        d++;
        outCnt++;
        for (bit = 0; bit < 8; bit++) {
            fbyte = (u8)(fbyte * 2);
            if (rem != 0) {
                mlen = fn_8020533C(&q, s, rem, &dist, window);
                if (mlen != 0) {
                    fbyte |= 1;
                    if (outCnt + 2 >= limit) {
                        return 0;
                    }
                    if (flg != 0) {
                        if (mlen >= 0x111) {
                            code = mlen - 0x111;
                            outCnt += 2;
                            d[0] = (u8)((code >> 12) | 0x10);
                            d[1] = (u8)(code >> 4);
                            d += 2;
                        } else if (mlen >= 0x11) {
                            code = mlen - 0x11;
                            outCnt += 1;
                            d[0] = (u8)(code >> 4);
                            d += 1;
                        } else {
                            code = mlen - 1;
                        }
                    } else {
                        code = mlen - 3;
                    }
                    sp = s;
                    ci = 0;
                    outCnt += 2;
                    d[0] = (u8)((code << 4) | ((dist - 1) >> 8));
                    d[1] = (u8)(dist - 1);
                    d += 2;
                    while (ci < (u32)mlen) {
                        fn_80205474(&q, sp++);
                        ci++;
                    }
                    s += mlen;
                    rem -= mlen;
                } else {
                    if (outCnt + 1 >= limit) {
                        return 0;
                    }
                    fn_80205474(&q, s);
                    d[0] = s[0];
                    rem -= 1;
                    outCnt += 1;
                    s += 1;
                    d += 1;
                }
            }
        }
        *fptr = fbyte;
    }
    pad = 0;
    while ((outCnt + pad) & 3) {
        *d++ = 0;
        pad++;
    }
    return outCnt;
}
