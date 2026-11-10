#pragma force_active on

extern int lbl_80529918[];
extern char lbl_80529CF8[];

extern void *fn_8022EE58(unsigned short);
extern void fn_80232034(unsigned char *, const unsigned char *);
extern void fn_802324E0(void *);
extern void fn_802324FC(void *, int, int);
extern int fn_8023251C(int);
extern unsigned char fn_80238D34(int);
extern unsigned char fn_8023C69C(int, void *);
extern void *fn_8023C8BC(void);
extern int fn_8023C974(int);
extern void fn_802337D0(void *);
extern int fn_8023F404(void (*)(int, int, const char *));
extern void fn_80233B74(int, int, const char *);
extern void fn_80233BB4(char *);

void fn_80232E68(unsigned char *arg0) {
    int p;
    short *q;
    short *r;
    int result;
    int ok = 1;
    unsigned char buf[0x210];

    result = (int)fn_8023C8BC();
    lbl_80529918[1] = result;
    if (result != 0) {
        ok = 0;
        if (lbl_80529918[2] != 0) {
            if (fn_80238D34(result + 2) != 0) {
                ((unsigned char *)lbl_80529918)[0x78] = 0;
            } else {
                ((unsigned char *)lbl_80529918)[0x78] = 1;
            }
            ((unsigned char *)lbl_80529918)[0x79] = 0;
            fn_8023F404(fn_80233B74);
            ((unsigned char *)lbl_80529918)[0x70] = 0;
            lbl_80529918[4] = 0;
            lbl_80529918[3] = lbl_80529918[2];
            ((unsigned char *)lbl_80529918)[0x20] = 0;
            fn_80232034((unsigned char *)lbl_80529918 + 0x1a,
                        (unsigned char *)(lbl_80529918[1] + 2));
            fn_802337D0((void *)(lbl_80529918[1] + 2));
        } else {
            ok = 1;
            while (lbl_80529918[1] != 0) {
                if (*(unsigned char *)(lbl_80529918[1] + 0x10) != 0) {
                    fn_80232034(buf, (unsigned char *)(lbl_80529918[1] + 2));
                    buf[6] = 0;
                    *(int *)(buf + 0x100) = 0;
                    ((void (*)(int, unsigned char *))lbl_80529918[0])(2, buf);
                } else {
                    unsigned short v = *(unsigned short *)(lbl_80529CF8 + 0x64c);

                    if (v < 0x7530) {
                        fn_802324FC((char *)lbl_80529918 + 0x58,
                                    0x205, v + 0x64);
                    }
                    if (fn_8023C69C(lbl_80529918[1] + 2,
                                   fn_80233BB4) != 1) {
                        fn_8023251C((int)lbl_80529918 + 0x58);
                        p = lbl_80529918[1] + 2;
                        q = (short *)fn_8022EE58(0x110);
                        if (q != 0) {
                            fn_80232034((unsigned char *)q + 8,
                                        (unsigned char *)p);
                            *((unsigned char *)q + 0xe) = 0;
                            *q = 0x204;
                            fn_802324E0(q);
                        }
                    }
                    ok = 0;
                    break;
                }
                lbl_80529918[1] = fn_8023C974(lbl_80529918[1]);
            }
        }
    }
    if (ok != 0) {
        lbl_80529918[2] = 0;
        r = (short *)fn_8022EE58(0x110);
        if (r != 0) {
            *r = 0x207;
            fn_802324E0(r);
        }
    }
    buf[0x108] = arg0[8];
    ((void (*)(int, unsigned char *))lbl_80529918[0])(1, buf + 0x108);
}
