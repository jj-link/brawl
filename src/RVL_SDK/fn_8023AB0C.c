#pragma force_active on
extern char lbl_805297D0[];
extern char lbl_80529CF8[];
extern void fn_80231FB0(char *p, int a, int b);
extern void fn_8023DC04(void);
extern void fn_80245D40(void);
extern int fn_8024663C(int a, int b, int c, int d);
extern int fn_802467FC(void);
extern int fn_802468E0(void);
extern void fn_8024D0DC(unsigned short x);

void fn_8023AB0C(unsigned char* p) {
    char* base;
    unsigned short v;
    if (p[0] == 0) {
        base = lbl_805297D0;
        v = p[1] + (p[2] << 8);
        *(unsigned short*)(base + 0x7c) = v;
        {
            unsigned short w = p[4] + (p[5] << 8);
            *(unsigned short*)(base + 0x7e) = v + 4;
            fn_8024D0DC(w);
        }
        fn_8024663C(0x69b, 0x1e, 0x14, 0xa);
    }
    lbl_80529CF8[0x64E] = 3;
    lbl_80529CF8[0x64F] = 4;
    if (lbl_80529CF8[0x64F] != 4) {
        lbl_80529CF8[0x64F] = 4;
        lbl_80529CF8[0x64E] = 4;
        fn_80231FB0(lbl_80529CF8 + 0x574, 1, 1);
        fn_80245D40();
        return;
    }
    fn_80231FB0(lbl_80529CF8 + 0x574, 1, 1);
    fn_802467FC();
    fn_802468E0();
    fn_8023DC04();
}
