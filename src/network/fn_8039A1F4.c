#pragma force_active on
extern int lbl_805A1170;
extern int lbl_805A1174;
extern int fn_803998CC(void);
extern int fn_803A49A8(void);
extern int fn_803A0EC4(void);

int fn_8039A1F4(void) {
    int result;
    if (lbl_805A1174 != 1) return -9;
    result = fn_803998CC();
    if (result != 0) return result;
    result = fn_803A49A8();
    if (result < 0) return result;
    result = fn_803A0EC4();
    if (result != 0) return result;
    lbl_805A1170 = 0;
    lbl_805A1174 = 0;
    return result;
}