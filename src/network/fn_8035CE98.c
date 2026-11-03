#pragma force_active on
extern int fn_803A84F0(int, int, int, void *, int *);
extern int lbl_805A1044;

static inline int convert(int result) {
    if (result >= 0) {
        return result;
    }
    lbl_805A1044 = result;
    return -1;
}

int fn_8035CE98(int arg) {
    int value;
    int size = 4;
    int result = convert(fn_803A84F0(arg, 0xFFFF, 0x1001, &value, &size));
    if (result == -1) {
        return -1;
    }
    return value;
}
