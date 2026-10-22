#pragma force_active on
extern int lbl_805A0FA8;
int fn_80335238(void);
int fn_80389934(int, int);
int fn_80388794(int, int, int);

int fn_8033CA34(int arg0, int arg1, int arg2) {
    int r;
    if (lbl_805A0FA8 == 0 || fn_80335238() != 0) {
        return arg2;
    }
    r = fn_80389934(*(int *)(lbl_805A0FA8 + 0xf8), arg0);
    if (r != 0) {
        return fn_80388794(r, arg1, arg2);
    }
    return arg2;
}
