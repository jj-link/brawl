#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, u16, int, u32);
extern u8 lbl_8052CDC0[];
extern char lbl_80483DCC[];

void fn_8024EF78(u8 *self, u8 *cfg)
{
    u16 len = 0;
    u8 *packet;
    u8 *p;
    if (cfg[2]) len = 4;
    if (cfg[0x20]) len += 4;
    if (cfg[6]) len += 0x18;
    if (cfg[0x24]) len += 0xB;
    packet = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), (u16)(len + 6), 5, self[0x36]);
    if (packet == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, lbl_80483DCC);
    } else {
        p = packet + 0x1A;
        packet[0x14] = *(u16 *)(self + 0x16);
        packet[0x15] = *(u16 *)(self + 0x16) >> 8;
        packet[0x16] = 0;
        packet[0x17] = 0;
        packet[0x18] = *(u16 *)cfg;
        packet[0x19] = *(u16 *)cfg >> 8;
        if (cfg[2]) {
            p[0] = 1;
            p[1] = 2;
            p[2] = *(u16 *)(cfg + 4);
            p[3] = *(u16 *)(cfg + 4) >> 8;
            p += 4;
        }
        if (cfg[0x20]) {
            p[0] = 2;
            p[1] = 2;
            p[2] = *(u16 *)(cfg + 0x22);
            p[3] = *(u16 *)(cfg + 0x22) >> 8;
            p += 4;
        }
        if (cfg[6]) {
            p[0] = 3;
            p[1] = 0x16;
            p[2] = cfg[8];
            p[3] = cfg[9];
            p[0x4] = *(u32 *)(cfg + 0xc);
            p[0x5] = *(u32 *)(cfg + 0xc) >> 8;
            p[0x6] = *(u32 *)(cfg + 0xc) >> 16;
            p[0x7] = *(u32 *)(cfg + 0xc) >> 24;
            p[0x8] = *(u32 *)(cfg + 0x10);
            p[0x9] = *(u32 *)(cfg + 0x10) >> 8;
            p[0xa] = *(u32 *)(cfg + 0x10) >> 16;
            p[0xb] = *(u32 *)(cfg + 0x10) >> 24;
            p[0xc] = *(u32 *)(cfg + 0x14);
            p[0xd] = *(u32 *)(cfg + 0x14) >> 8;
            p[0xe] = *(u32 *)(cfg + 0x14) >> 16;
            p[0xf] = *(u32 *)(cfg + 0x14) >> 24;
            p[0x10] = *(u32 *)(cfg + 0x18);
            p[0x11] = *(u32 *)(cfg + 0x18) >> 8;
            p[0x12] = *(u32 *)(cfg + 0x18) >> 16;
            p[0x13] = *(u32 *)(cfg + 0x18) >> 24;
            p[0x14] = *(u32 *)(cfg + 0x1c);
            p[0x15] = *(u32 *)(cfg + 0x1c) >> 8;
            p[0x16] = *(u32 *)(cfg + 0x1c) >> 16;
            p[0x17] = *(u32 *)(cfg + 0x1c) >> 24;
            p += 0x18;
        }
        if (cfg[0x24]) {
            p[0] = 4;
            p[1] = 9;
            p[2] = cfg[0x26];
            p[3] = cfg[0x27];
            p[4] = cfg[0x28];
            p[5] = *(u16 *)(cfg + 0x2A);
            p[6] = *(u16 *)(cfg + 0x2A) >> 8;
            p[7] = *(u16 *)(cfg + 0x2C);
            p[8] = *(u16 *)(cfg + 0x2C) >> 8;
            p[9] = *(u16 *)(cfg + 0x2E);
            p[10] = *(u16 *)(cfg + 0x2E) >> 8;
        }
        fn_8024CB94(*(u8 **)(self + 0x10), 0, packet);
    }
}
