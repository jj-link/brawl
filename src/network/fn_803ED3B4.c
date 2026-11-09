#pragma force_active on

extern int lbl_805A1280;
extern void fn_803EC3D4(int);
extern void fn_803EC418(int);
extern int fn_803EDCC8(int, int, int, int, int *, int);

int fn_803ED3B4(int arg0, int arg1, int arg2, int arg3, int *arg4)
{
    int result;

    fn_803EC3D4(lbl_805A1280);
    *arg4 = 0;
    if (arg0 == 0) {
        fn_803EC418(lbl_805A1280);
        return -0x14;
    }
    if (arg1 == 0) {
        fn_803EC418(lbl_805A1280);
        return -0x14;
    }
    result = fn_803EDCC8(arg3, arg1, arg2, 0x200, arg4, arg0);
    if (result != 0) {
        fn_803EC418(lbl_805A1280);
        return result;
    }
    fn_803EC418(lbl_805A1280);
    return 0;
}
