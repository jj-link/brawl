extern void OSInitMutex(void *);
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_803AE310(int, int);
extern void fn_803C2D74(int, int);
extern void fn_803C44BC(int, int);
extern void fn_803C6C80(int);
extern void fn_803C6DC4(void);
extern int lbl_805A1208;
extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];

#pragma force_active on
void fn_803C2F1C(int arg0, int arg1)
{
    if (lbl_805A120C == 0) {
        OSInitMutex(lbl_80563200);
        lbl_805A120C = 1;
    }
    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    if (lbl_805A1208 == 0) {
        lbl_805A1208 = 1;
        fn_803C44BC(arg0, arg1);
        fn_803AE310(0, 0);
        fn_803C2D74(0, 0);
        fn_803C6DC4();
        fn_803C6C80(0);
    }
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
}
