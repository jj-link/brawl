#pragma force_active on
extern int PFSTR_InitStr(int *p1, int p2, int p3);
extern void fn_803DC1C8(int *p1, int p2);
extern void PFAPI_convertReturnValue(void);
extern char lbl_805644C0[];

void fn_803EB7C4(int arg0, int arg1) {
    int local[4];
    int result = PFSTR_InitStr(local, arg0, 1);
    if (result == 0) {
        fn_803DC1C8(local, arg1);
    } else {
        *(int*)(lbl_805644C0 + 0x40) = result;
    }
    PFAPI_convertReturnValue();
}
