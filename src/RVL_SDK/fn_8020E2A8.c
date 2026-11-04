#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;

extern u8 lbl_804ED380[];
extern s8 lbl_805A0BB8;
extern int lbl_805A0BC8;
extern int lbl_805A0BC0;
extern int lbl_805A0BBC;
extern char lbl_8040D5B8[];
extern char lbl_8040D5D0[];
extern char lbl_8059EC78[5];
extern char lbl_8059EC80[5];
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);
extern void fn_8020E3BC(s32);
extern s32 fn_8020BB4C(void *, void *, s32, void *, void *);

s32 fn_8020E2A8(void *arg0, u32 arg1, s32 arg2)
{
    u8 *base;
    u8 *p;
    u32 idx;

    if (arg1 < 0x4000) {
        return -0x80;
    }

    base = lbl_804ED380;
    *(u32 *)(base + 0x15c) = (u32)arg2;
    lbl_805A0BB8 = 1;
    *(u32 *)(base + 0x160) = 0;
    base[0x15a] = 0;
    *(u32 *)(base + 0x17c) = 0;
    *(u32 *)(base + 0x180) = 0;
    *(u32 *)(base + 0x164) = (u32)&lbl_8040D5B8;
    *(u32 *)(base + 0x168) = (u32)&lbl_8040D5D0;
    *(u32 *)(base + 0x16c) = (u32)arg0;
    *(u32 *)(base + 0x170) = 0x80003800;
    *(u32 *)(base + 0x174) = 0x4000;
    *(u32 *)(base + 0x178) = 0x100;

    memset(arg0, 0, 0x4000);
    memcpy(arg0, &lbl_8059EC78, 4);
    memcpy((u8 *)arg0 + 0x3ffc, &lbl_8059EC80, 4);
    *(u16 *)((u8 *)arg0 + 0x6) = 8;

    base[0x159] = 0;
    idx = base[0x15a];
    p = base + idx * 4;
    lbl_805A0BC8 = 0;
    lbl_805A0BC0 = 0;
    lbl_805A0BBC = 0;
    return fn_8020BB4C((void *)(u32)(*(u32 *)(p + 0x164)), base + 8, 1, fn_8020E3BC, base + 0x94);
}
