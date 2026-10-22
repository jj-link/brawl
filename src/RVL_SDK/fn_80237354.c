#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void *fn_8022EE58(unsigned short size);
extern void fn_802319E4(unsigned int id, const char *msg);
extern void fn_80232034(void *dst, int src);
extern void fn_802324E0(void *arg);
extern void *memset(void *dst, int c, unsigned int n);
extern char lbl_80480328[];
extern u8 lbl_805A0D30;

void fn_80237354(int arg0, u8 arg1, u8 arg2) {
    u8 *p;

    p = (u8 *)fn_8022EE58(0x10);
    if (p != 0) {
        memset(p, 0, 0x10);
        *(u16 *)(p + 0) = 0x1700;
        *(u16 *)(p + 6) = 0xFF;
        p[0xE] = arg2;
        p[0xF] = arg1;
        fn_80232034(p + 8, arg0);
        fn_802324E0(p);
        return;
    }
    if (lbl_805A0D30 >= 1) {
        fn_802319E4(0x500, lbl_80480328);
    }
}
