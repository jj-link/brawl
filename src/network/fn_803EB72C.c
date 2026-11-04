#pragma force_active on
extern int PFSTR_InitStr(int*, int, int);
extern int fn_803DC060(int*, int, int);
extern int PFAPI_convertReturnValue(int);
extern char lbl_805644C0[];

int fn_803EB72C(int arg0, int arg1, int arg2) {
    int local[4];
    int result = PFSTR_InitStr(local, arg0, 1);
    if (result == 0) {
        result = fn_803DC060(local, arg1, arg2);
    } else {
        *(int*)(lbl_805644C0 + 0x40) = result;
    }
    return PFAPI_convertReturnValue(result);
}
