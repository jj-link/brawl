#pragma force_active on
extern int lbl_80599680[];

int fn_803EEB9C(int a, int b, int c, int d, int e);

int fn_803EE610(int a, int b, int c, int d, int e) {
    if (a == 0 || b == 0 || e == 0) {
        return 1;
    }
    return fn_803EEB9C(d, b, c, lbl_80599680[1], e);
}
