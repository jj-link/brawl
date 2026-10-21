#pragma force_active on
extern int lbl_805A1048;
int fn_803689DC(int arg);

int fn_80367C28(int arg) {
    if (lbl_805A1048 != 1) {
        return 2;
    }
    if (arg == 0) {
        return 2;
    }
    return fn_803689DC(arg);
}
