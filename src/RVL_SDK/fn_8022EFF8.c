#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_804FD448[];
extern void fn_8023052C(void);
extern void fn_80230508(void);
extern s8 fn_80230500(void);
extern void *fn_8022EE58(u16 size);

void *fn_8022EFF8(u32 arg0) {
    u32 off;
    u8 *block;
    u8 *base = lbl_804FD448 + 0x54;
    u8 *p;
    u8 *next;
    u16 n;

    if (arg0 >= 9) {
        return 0;
    }
    fn_8023052C();
    off = (arg0 << 4) & 0xFF0;
    p = base + 0x30000 + off;
    if (*(u16 *)(p - 0x7668) < *(u16 *)(p - 0x766a)) {
        block = *(u8 **)(p - 0x7674);
        next = *(u8 **)block;
        *(u8 **)(p - 0x7674) = next;
        if (next == 0) {
            *(u32 *)(p - 0x7670) = 0;
        }
        n = *(u16 *)(p - 0x7668) + 1;
        *(u16 *)(p - 0x7668) = n;
        if (n > *(u16 *)(p - 0x7666)) {
            *(u16 *)(p - 0x7666) = *(u16 *)(p - 0x7668);
        }
        fn_80230508();
        block[5] = fn_80230500();
        block[6] = 1;
        *(u8 **)block = 0;
        block[7] = 0;
        return block + 8;
    }
    fn_80230508();
    return fn_8022EE58(*(u16 *)(base + 0x30000 + off - 0x766c));
}
