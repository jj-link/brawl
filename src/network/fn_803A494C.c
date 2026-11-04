#pragma force_active on
extern int fn_803A4D00(void);
extern int fn_803A2708(int);
extern int fn_803A49B0(void *, int);
extern char *lbl_805A1170;

int fn_803A494C(void) {
    int result;
    char *ptr;
    result = fn_803A4D00();
    if (result >= 0) {
        fn_803A2708(0);
        if (lbl_805A1170 != 0) {
            ptr = lbl_805A1170 + 0x3600;
        } else {
            ptr = 0;
        }
        result = fn_803A49B0(ptr, 0);
        if (result >= 0) {
            result = 0;
        }
    }
    return result;
}