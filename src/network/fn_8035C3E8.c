#pragma force_active on
extern int fn_803A70FC(void);
extern int lbl_805A1044;

int listen(void) {
    int temp_r3;

    temp_r3 = fn_803A70FC();
    if (temp_r3 >= 0) {
        return temp_r3;
    }
    lbl_805A1044 = temp_r3;
    return -1;
}
