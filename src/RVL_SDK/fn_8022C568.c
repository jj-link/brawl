#pragma force_active on
extern char lbl_8047EF84[];
extern char lbl_804FB4A0[];
extern unsigned char lbl_805A3A48, lbl_805A3A49, lbl_805A3A4A, lbl_805A3A4B, lbl_805A3A4C, lbl_805A3A4D, lbl_805A3A4E;
extern void fn_8022DA30(void);
extern void fn_8022DD6C(void);
extern void fn_8022E0A8(void);
extern void fn_8022E928(void*, ...);
extern void fn_80234BF8(void*);
extern void fn_80234C5C(int, int);
extern void fn_80238958(int);
extern void fn_80238D24(int);
extern void fn_8023B3A4(void*);
extern void fn_8023B444(void*);
extern void fn_8023B5C4(void*);
extern void fn_8023B694(unsigned short);
extern void fn_8023D8C0(int, void*, void*);
extern void fn_8022C6F4(void*);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

void fn_8022C568(void) {
    unsigned char a[4];
    unsigned char b[4];
    int i;
    char* p;
    char* q;
    char* base = lbl_804FB4A0;
    int lv;
    a[0] = lbl_805A3A48;
    a[1] = lbl_805A3A49;
    a[2] = lbl_805A3A4A;
    a[3] = lbl_805A3A4B;
    b[0] = lbl_805A3A4C;
    b[1] = lbl_805A3A4D;
    b[2] = lbl_805A3A4E;
    fn_8022E928(lbl_8047EF84);
    fn_80234BF8(a);
    fn_8023B3A4(b);
    fn_8023B5C4(fn_8022DA30);
    fn_8023B444(fn_8022DD6C);
    fn_8023D8C0(3, base + 0x70A, fn_8022E0A8);
    fn_8023B694(0x10000 - 0x8000);
    fn_80238958(5);
    fn_80238D24(0xC80);
    p = base;
    q = base + 0x124;
    for (i = 0; i < 10; i++) {
        if (*(unsigned char*)(p + 0x13d) == 1) fn_8022C6F4(q);
        p += 0x60;
        q += 0x60;
    }
    p = base;
    q = base + 0x4E4;
    for (i = 0; i < 6; i++) {
        if (*(unsigned char*)(p + 0x4fd) == 1) fn_8022C6F4(q);
        p += 0x60;
        q += 0x60;
    }
    lv = OSDisableInterrupts();
    base[0x708] = 3;
    OSRestoreInterrupts(lv);
    lv = OSDisableInterrupts();
    lbl_804FB4A0[0x6EB] = 0;
    lbl_804FB4A0[0x6EA] = 1;
    OSRestoreInterrupts(lv);
    fn_80234C5C(0, 1);
}
