#pragma force_active on
extern int lbl_80599680[];
int fn_803EE9A0(int, int, int, int, int);

int fn_803EE5D8(int a0, int a1, int a2, int a3, int a4) {
    if (a0 == 0 || a1 == 0 || a4 == 0) {
        return 1;
    }
    return fn_803EE9A0(a3, a1, a2, lbl_80599680[1], a4);
}
