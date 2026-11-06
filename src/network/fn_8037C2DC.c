#pragma force_active on
extern int lbl_805A1070;
extern int **lbl_805A1074;
extern void *fn_8035DFE8(int);
extern void *fn_8035DFF8(void *, int);
extern void fn_8035E00C(void *);

int fn_8037C2DC(void) {
    int i;
    int old, end;
    int **p;
    for (i = 0; i < lbl_805A1070; i++) {
        if (*lbl_805A1074[i] == 0)
            return i;
    }
    old = lbl_805A1070;
    end = old + 4;
    p = fn_8035DFF8(lbl_805A1074, end * 4);
    if (p == 0)
        return -1;
    lbl_805A1074 = p;
    for (i = old; i < end; i++) {
        lbl_805A1074[i] = fn_8035DFE8(0x1b4);
        if (lbl_805A1074[i] == 0) {
            for (i--; i >= old; i--)
                fn_8035E00C(lbl_805A1074[i]);
            return -1;
        }
        *lbl_805A1074[i] = 0;
    }
    lbl_805A1070 = end;
    return old;
}