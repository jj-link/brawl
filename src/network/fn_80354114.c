#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern char lbl_8048DBD0[], lbl_8048DBE8[];
extern char lbl_80534030[];
extern char *lbl_805A0FD4;
extern int lbl_805A0FD8;
void fn_80354114(int a, int b, int c, int d) {
    int x;
    char *p;
    *(int *)(lbl_805A0FD4 + 0x59d8) = 0;
    if (b != 27 && *(int *)(lbl_805A0FD4 + 0x59dc) == -3 && *(int *)(lbl_805A0FD4 + 0x59d4) < 5) {
        ++*(int *)(lbl_805A0FD4 + 0x59d4);
        lbl_805A0FD8 = b;
        return;
    }
    *(int *)(lbl_805A0FD4 + 0x59d4) = 0;
    x = *(int *)(lbl_805A0FD4 + 0x59dc);
    if (x == 0) { lbl_805A0FD8 = a; return; }
    if (c != 27 && x == -12) { lbl_805A0FD8 = c; return; }
    if (d != 27 && x == -1) { lbl_805A0FD8 = d; return; }
    fn_80335638(0x1000000, lbl_8048DBE8, x);
    p = lbl_805A0FD4;
    x = *(int *)(p + 0x59dc);
    *(int *)lbl_80534030 = ((~((x + 4) | (-4 - x))) >> 31) - 0x7148;
    fn_80335638(0x1000000, lbl_8048DBD0);
    ((void (*)(int, void *, int))(*(int *)(lbl_805A0FD4 + 0x5b34)))(0, lbl_805A0FD4, 0);
    lbl_805A0FD4 = 0;
    lbl_805A0FD8 = 25;
}
