#pragma force_active on
extern int fn_803A9DF8(int, void *, int, int, int);
extern unsigned char lbl_8059FE88;
extern unsigned char lbl_8059FE89;

int fn_803BFA20(int arg0) {
    unsigned char bytes[2];
    int result = 0;
    bytes[0] = lbl_8059FE88;
    bytes[1] = lbl_8059FE89;
    if (arg0 == 0) {
        return 10;
    }
    if (fn_803A9DF8(arg0, bytes, 1, 0, 2) == 0) {
        result = 1;
    }
    return result;
}