#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, u16, int, u8);
extern u8 lbl_8052CDC0[];
extern char lbl_80483DCC[];

void fn_8024EC80(u8 *self, u8 *arg)
{
    u8 *p;
    u16 n;
    u8 *q;
    u8 t;

    n = 0;
    p = *(u8 **)(self + 0x10);
    t = p[0x31] + 1;
    p[0x31] = t;
    self[0x35] = t;
    if (arg[2] != 0) {
        n = 4;
    }
    if (arg[0x20] != 0) {
        n += 4;
    }
    if (arg[6] != 0) {
        n += 0x18;
    }
    if (arg[0x24] != 0) {
        n += 0xB;
    }
    p = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), (u16)(n + 4), 4, self[0x35]);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483DCC);
        }
    } else {
        q = p + 0x18;
        p[0x14] = (u8)*(u16 *)(self + 0x16);
        p[0x15] = (u8)(*(u16 *)(self + 0x16) >> 8);
        p[0x16] = 0;
        p[0x17] = 0;
        if (arg[2] != 0) {
            q[0] = 1;
            q[1] = 2;
            q[2] = (u8)*(u16 *)(arg + 4);
            q[3] = (u8)(*(u16 *)(arg + 4) >> 8);
            q += 4;
        }
        if (arg[0x20] != 0) {
            q[0] = 2;
            q[1] = 2;
            q[2] = (u8)*(u16 *)(arg + 0x22);
            q[3] = (u8)(*(u16 *)(arg + 0x22) >> 8);
            q += 4;
        }
        if (arg[6] != 0) {
            q[0] = 3;
            q[1] = 0x16;
            q[2] = arg[8];
            q[3] = arg[9];
            q[4] = (u8)*(u32 *)(arg + 0xC);
            q[5] = (u8)(*(u32 *)(arg + 0xC) >> 8);
            q[6] = (u8)(*(u32 *)(arg + 0xC) >> 16);
            q[7] = (u8)(*(u32 *)(arg + 0xC) >> 24);
            q[8] = (u8)*(u32 *)(arg + 0x10);
            q[9] = (u8)(*(u32 *)(arg + 0x10) >> 8);
            q[10] = (u8)(*(u32 *)(arg + 0x10) >> 16);
            q[11] = (u8)(*(u32 *)(arg + 0x10) >> 24);
            q[12] = (u8)*(u32 *)(arg + 0x14);
            q[13] = (u8)(*(u32 *)(arg + 0x14) >> 8);
            q[14] = (u8)(*(u32 *)(arg + 0x14) >> 16);
            q[15] = (u8)(*(u32 *)(arg + 0x14) >> 24);
            q[16] = (u8)*(u32 *)(arg + 0x18);
            q[17] = (u8)(*(u32 *)(arg + 0x18) >> 8);
            q[18] = (u8)(*(u32 *)(arg + 0x18) >> 16);
            q[19] = (u8)(*(u32 *)(arg + 0x18) >> 24);
            q[20] = (u8)*(u32 *)(arg + 0x1C);
            q[21] = (u8)(*(u32 *)(arg + 0x1C) >> 8);
            q[22] = (u8)(*(u32 *)(arg + 0x1C) >> 16);
            q[23] = (u8)(*(u32 *)(arg + 0x1C) >> 24);
            q += 0x18;
        }
        if (arg[0x24] != 0) {
            q[0] = 4;
            q[1] = 9;
            q[2] = arg[0x26];
            q[3] = arg[0x27];
            q[4] = arg[0x28];
            q[5] = (u8)*(u16 *)(arg + 0x2A);
            q[6] = (u8)(*(u16 *)(arg + 0x2A) >> 8);
            q[7] = (u8)*(u16 *)(arg + 0x2C);
            q[8] = (u8)(*(u16 *)(arg + 0x2C) >> 8);
            q[9] = (u8)*(u16 *)(arg + 0x2E);
            q[10] = (u8)(*(u16 *)(arg + 0x2E) >> 8);
        }
        fn_8024CB94(*(void **)(self + 0x10), 0, p);
    }
}
