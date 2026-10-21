#pragma force_active on
extern int lbl_805A1044;

int fn_803A75E4(int a, int b, int c, int d);

int recv(int a, int b, int c) {
    int r = fn_803A75E4(a, b, c, 4);
    if (r >= 0) {
        return r;
    } else {
        lbl_805A1044 = r;
        return -1;
    }
}
