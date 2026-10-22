#pragma force_active on
typedef unsigned char u8;

extern void fn_80232780(void *);
extern void *memset(void *, int, unsigned long);
extern char lbl_80529AC8[];

void fn_80237C90(void *arg0) {
    u8 r31;
    u8 r5;

    r5 = *((u8 *)arg0 + 0x16);
    if (r5 != 0xFF) {
        *(u8 *)(lbl_80529AC8 + r5 + 0x214) = 0x10;
    }
    r31 = *((u8 *)arg0 + 0x12);
    fn_80232780((u8 *)arg0 + 4);
    memset(arg0, 0, 0x20);
    *((u8 *)arg0 + 0x12) = r31;
    *((u8 *)arg0 + 0x1C) = 1;
    *((u8 *)arg0 + 0x16) = 0xFF;
}
