#pragma force_active on
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef signed int s32; typedef signed char s8;
extern u8 lbl_804ED380[]; extern s8 lbl_805A0BB8; extern char lbl_8059EC78[5]; extern char lbl_8059EC80[5];
extern void *memset(void *, int, u32); extern void *memcpy(void *, const void *, u32); extern void fn_8020E3BC(s32); extern s32 fn_8020BB4C(void *, void *, s32, void *, void *);
void fn_8020E600(void) {
    u8 *base = lbl_804ED380; u8 *arg0; s32 r28; u32 idx;
loop:
    idx = base[0x15a]; idx = idx + 1; base[0x15a] = idx;
    if ((idx & 0xff) < 2) {
        base[0x159] = 0;
        if (fn_8020BB4C((void *)(u32)(*(u32 *)(base + ((u8)idx * 4) + 0x164)), base + 8, 1, fn_8020E3BC, base + 0x94) != 0) goto loop;
        return;
    }
    switch (*(s32 *)(base + 0x160)) {
    case 0: r28 = 3; break;
    case -12:
    default:
        arg0 = (u8 *)(u32)(*(u32 *)(lbl_804ED380 + 0x16C));
        memset(arg0, 0, 0x4000);
        memcpy(arg0, &lbl_8059EC78, 4);
        memcpy(arg0 + 0x3FFC, &lbl_8059EC80, 4);
        *(u16 *)(arg0 + 6) = 8;
        *(u32 *)(lbl_804ED380 + 0x17C) = *(u32 *)(lbl_804ED380 + 0x174);
        r28 = 3;
        break;
    }
    *(u8 *)0x800038FF = 0;
    { s32 callback = *(s32 *)(lbl_804ED380 + 0x15C); if (callback != 0) { ((void (*)(s32))(u32)callback)(*(s32 *)(lbl_804ED380 + 0x160)); *(u32 *)(lbl_804ED380 + 0x15C) = 0; } }
    lbl_805A0BB8 = r28;
}