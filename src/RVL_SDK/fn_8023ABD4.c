#pragma force_active on
extern char lbl_80529CF8[];
extern void fn_80231FB0(void*, int, int);
extern void fn_80245D40(void);
extern void fn_8024685C(void);

void fn_8023ABD4(unsigned char* p) {
    char* a = lbl_80529CF8;
    char* b;
    if (p[0] == 0) {
        a[0x636] = p[1];
        *(short*)(a + 0x638) = p[2] + (p[3] << 8);
        a[0x63A] = p[4];
        *(short*)(a + 0x63C) = p[5] + (p[6] << 8);
        *(short*)(a + 0x63E) = p[7] + (p[8] << 8);
    }
    b = lbl_80529CF8;
    b[0x64E] = 4;
    b[0x64F] = 4;
    if (b[0x64E] != 4) {
        b[0x64F] = 4;
        b[0x64E] = 4;
        fn_80231FB0(b + 0x574, 1, 1);
        fn_80245D40();
        return;
    }
    fn_80231FB0(b + 0x574, 1, 1);
    fn_8024685C();
}
