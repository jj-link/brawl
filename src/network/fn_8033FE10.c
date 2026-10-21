#pragma force_active on
extern int lbl_805A0F94;

int fn_8033FE10(int a, int b) {
    if (lbl_805A0F94 == 0) {
        return 1;
    }
    if (a == 0 || b == 0) {
        return 0;
    }
    return __abs(a - b) <= 1;
}
