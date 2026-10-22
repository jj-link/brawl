#pragma force_active on
extern unsigned char lbl_805A0D30;
extern char lbl_8047FF74[];
void fn_802319FC(int, void *, int);
void fn_80232034(void *, void *);
void fn_80235F38(void *, void *);
void fn_80237600(void *, int, void *);
void *memset(void *, int, unsigned long);

void fn_802363C4(char *a, char *b) {
    char buf[16];
    int r;
    if (b != 0) {
        r = (unsigned char)*(unsigned short *)(b + 6);
    } else {
        r = *(unsigned char *)(a + 0x16);
    }
    if (lbl_805A0D30 >= 4) {
        fn_802319FC(0x503, lbl_8047FF74, r);
    }
    if (*(unsigned char *)(a + 0x15) != 0) {
        fn_80237600(a, 0x170b, b);
        return;
    }
    *(unsigned char *)(a + 0x19) = 1;
    memset(buf, 0, 0x10);
    fn_80232034(buf + 8, a + 8);
    fn_80235F38(a, buf);
}
