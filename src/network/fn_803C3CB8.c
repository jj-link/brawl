#pragma force_active on

extern void fn_803C4158(int);
extern int fn_803C6194(int*, int);

int fn_803C3CB8(int arg0) {
    int sp8 = -1;
    int res = fn_803C6194(&sp8, arg0);
    if (res != 0) {
        fn_803C4158(res);
    }
    return sp8;
}
