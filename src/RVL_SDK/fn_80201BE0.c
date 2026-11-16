#pragma force_active on

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern s32 lbl_804780E0[];
extern s32 lbl_80478160[];
extern s32 lbl_805A0B28;
extern s32 lbl_805A0B2C;
extern s32 lbl_805A0B34;
extern s32 lbl_805A0B38;
extern u32 lbl_805A0B3C;
extern u32 lbl_805A0B40;

void DCFlushRange(void *buf, u32 len);
void fn_801D76BC(void *dst, u32 len);
void *fn_801FF1FC(s32 idx);
void fn_801FF438(void *node);
s32 fn_801FFF90(void);
void fn_8020151C(void *obj);
void fn_80201690(void *node);

void fn_80201BE0(s32 arg0)
{
    s32 total;
    u32 i;
    char *node;
    char *item;
    u32 v;
    u16 x;
    u32 f;
    u32 r4v;
    s32 var;
    s32 sumA;
    s32 sumB;
    s32 sumC;
    s32 sumD;
    s32 sumE;
    s32 sumF;
    s32 sumG;

    lbl_805A0B38 = 0;
    fn_801D76BC((void *)lbl_805A0B28, lbl_805A0B34 * 0x140);
    fn_801D76BC((void *)lbl_805A0B2C, lbl_805A0B34 << 6);
    v = (u32)((char *)fn_801FFF90() + lbl_805A0B34 * 0x258);
    v = (u32)((char *)v + arg0);
    total = v + 0x20;
    i = 0x1F;
    do {
        node = fn_801FF1FC(i);
        while (node != 0) {
            if (*(u16 *)(node + 0x6C) == 1) {
                total += 0x81;
            }
            if (*(s32 *)(node + 0x20) != 0) {
                fn_8020151C((void *)(lbl_805A0B28 + *(s32 *)(node + 0x18) * 0x140));
            }
            if (*(u16 *)(node + 0x38) == 1) {
                total += 0x183;
                if (*(u16 *)(node + 0xE2) != 0) {
                    total += 0x135;
                }
                if (*(u16 *)(node + 0xEA) != 0) {
                    total += 0x400;
                }
                if (*(u16 *)(node + 0x6C) == 1) {
                    total += 0x1B;
                }
                f = *(u16 *)(node + 0x30);
                r4v = ((u32)*(u16 *)(node + 0xCE) << 16) | *(u16 *)(node + 0xD0);
                if (f == 0) {
                    var = (s32)((((r4v << 9) + 0x8000) >> 16) + 0x619);
                } else {
                    var = 0x25D;
                    if (f == 1) {
                        var = (s32)((((r4v << 9) + 0x8000) >> 16) + 0x5BA);
                    }
                }
                v = *(u32 *)(node + 0x34);
                total += var;
                total += lbl_804780E0[v & 0x1F] + lbl_804780E0[(v >> 16) & 0x1F] + lbl_804780E0[(v >> 21) & 0x1F] + lbl_804780E0[(v >> 26) & 0x1F];
                if (*(u16 *)(node + 0xFE) == 1) {
                    total += 0x265;
                    f = *(u16 *)(node + 0x13C);
                    if (f == 1) {
                        total += 0x76;
                    } else if (f == 2) {
                        total += 0x342;
                    }
                    x = *(u16 *)(node + 0x100);
                    total += lbl_80478160[x & 3] + lbl_80478160[(x >> 2) & 3] + lbl_80478160[(x >> 4) & 3] + lbl_80478160[(x >> 6) & 3] + lbl_80478160[(x >> 8) & 3] + lbl_80478160[(x >> 10) & 3] + lbl_80478160[(x >> 12) & 3] + lbl_80478160[(x >> 14) & 3];
                }
                if (lbl_805A0B40 > (u32)total) {
                    fn_80201690(node);
                } else {
                    item = (char *)lbl_805A0B28 + *(s32 *)(node + 0x18) * 0x140;
                    if (*(u16 *)(item + 0x10) == 1) {
                        fn_8020151C(item);
                    }
                    *(u16 *)(node + 0x38) = 0;
                    *(u16 *)(item + 0x10) = 0;
                    fn_801FF438(node);
                }
            } else {
                fn_80201690(node);
            }
            *(s32 *)(node + 0x1C) = 0;
            *(s32 *)(node + 0x20) = 0;
            node = *(char **)node;
        }
        i--;
    } while (i != 0);
    lbl_805A0B3C = total;
    {
        char *last = fn_801FF1FC(0);
        while (last != 0) {
            if (*(s32 *)(last + 0x20) != 0) {
                fn_8020151C((void *)(lbl_805A0B28 + *(s32 *)(last + 0x18) * 0x140));
            }
            *(s32 *)(last + 0x20) = 0;
            *(u16 *)((char *)lbl_805A0B28 + *(s32 *)(last + 0x18) * 0x140 + 0x10) = 0;
            last = *(char **)last;
        }
    }
    DCFlushRange((void *)lbl_805A0B28, lbl_805A0B34 * 0x140);
    DCFlushRange((void *)lbl_805A0B2C, lbl_805A0B34 << 6);
}
