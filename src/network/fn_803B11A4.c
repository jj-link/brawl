#pragma force_active on
typedef unsigned short u16;

extern int lbl_8059FE28;
extern int lbl_8059FE2C;
extern int lbl_8059FE30;
extern int lbl_8059FE34;

extern int fn_803A9DF8(int, void *, int, int, int);
extern u16 fn_803A9C74(int, int);
extern void fn_803A9AD0(int, int);
extern int fn_803B35D0(void *, void *);
extern int fn_803C1054(void *, void *);
extern int fn_803B5638(void *, void *, void *, int, int);

int fn_803B11A4(void *arg0, int arg1)
{
    char req[0x70];
    char obj[0x240];
    int ret;

    if ((fn_803A9DF8(arg1, &lbl_8059FE28, 1, 0, 1) == 0 ||
         fn_803A9DF8(arg1, &lbl_8059FE2C, 1, 0, 1) == 0) &&
        fn_803A9DF8(arg1, &lbl_8059FE30, 1, 1, 1) == 0) {
        ret = fn_803B35D0(arg0, obj);
        if (ret != 0) {
            return ret;
        }
        ret = fn_803C1054(arg0, obj);
        return ret & ((-ret | ret) >> 31);
    }

    if (fn_803A9C74(arg1, 1) == 2 &&
        fn_803A9DF8(arg1, &lbl_8059FE34, 1, 1, 1) == 0) {
        return 0;
    }

    if (fn_803A9C74(arg1, 1) == 3 &&
        fn_803A9DF8(arg1, &lbl_8059FE34, 1, 1, 1) == 0 &&
        (fn_803A9DF8(arg1, &lbl_8059FE28, 1, 2, 1) == 0 ||
         fn_803A9DF8(arg1, &lbl_8059FE2C, 1, 2, 1) == 0)) {
        ret = fn_803B35D0(arg0, obj);
        if (ret != 0) {
            return ret;
        }
        ret = fn_803C1054(arg0, obj);
        return ret & ((-ret | ret) >> 31);
    }

    if (fn_803A9DF8(arg1, &lbl_8059FE34, 1, 1, 1) == 0 &&
        (fn_803A9DF8(arg1, &lbl_8059FE28, 1, 2, 1) == 0 ||
         fn_803A9DF8(arg1, &lbl_8059FE2C, 1, 2, 1) == 0)) {
        fn_803A9AD0(arg1, 2);
    }

    ret = fn_803B5638(req, obj, arg0, arg1, 0);
    if (ret != 0) {
        return ret;
    }

    if (!(obj[0x21c] & 0x10)) {
        return 0x14;
    }

    ret = fn_803C1054(arg0, obj);
    return ret & ((-ret | ret) >> 31);
}
