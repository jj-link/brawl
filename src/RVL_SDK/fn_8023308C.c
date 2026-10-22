#pragma force_active on
extern int lbl_80529918[];
extern char lbl_80529CF8[];
extern void *fn_8022EE58(unsigned short size);
extern void fn_80232034(unsigned char *dst, const unsigned char *src);
extern void fn_802324E0(void *);
extern void fn_802324FC(void *, int, int);
extern int fn_8023251C(int);
extern unsigned char fn_8023C69C(int, void *);
extern int fn_8023C974(int);
extern void fn_80233BB4(char *);

void fn_8023308C(unsigned char *self) {
    int p;
    short *q;
    int ok = 1;
    while ((lbl_80529918[1] = fn_8023C974(lbl_80529918[1])) != 0) {
        if (*(unsigned char *)(lbl_80529918[1] + 0x10) != 0) {
            unsigned char buf[0x110];
            fn_80232034(buf, (unsigned char *)(lbl_80529918[1] + 2));
            buf[6] = 0;
            *(int *)(buf + 0x100) = 0;
            ((void (*)(int, unsigned char *))lbl_80529918[0])(2, buf);
            continue;
        }
        {
            unsigned short v = *(unsigned short *)(lbl_80529CF8 + 0x64C);
            if (v < 0x7530) fn_802324FC((char *)lbl_80529918 + 0x58, 0x205, v + 0x64);
        }
        if (fn_8023C69C(lbl_80529918[1] + 2, fn_80233BB4) != 1) {
            fn_8023251C((int)lbl_80529918 + 0x58);
            p = lbl_80529918[1] + 2;
            q = (short *)fn_8022EE58(0x110);
            if (q) {
                fn_80232034((unsigned char *)q + 8, (unsigned char *)p);
                *((unsigned char *)q + 0xE) = 0;
                *q = 0x204;
                fn_802324E0(q);
            }
        }
        ok = 0;
        break;
    }
    if (ok) {
        short *r = (short *)fn_8022EE58(0x110);
        if (r) {
            *r = 0x207;
            fn_802324E0(r);
        }
    }
    ((void (*)(int, unsigned char *))lbl_80529918[0])(2, self + 8);
}
