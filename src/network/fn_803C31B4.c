extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern int fn_803C30C0(int, int, int);
extern void fn_803C4158(int);
extern int fn_803C47CC(int *, int, int);
extern int fn_803C49B8(void);
extern void fn_803C68D8(void);
extern int fn_803C7058(int);
extern void fn_803C70B8(int, int);
extern void fn_803C72A0(int);
extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];

#pragma force_active on
int fn_803C31B4(int arg0, int arg1)
{
    int sp8;
    int result;
    int r3;
    int temp;

    result = 0xB004;
    sp8 = -1;

    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }

    if (fn_803C7058(arg0) == -1) {
        r3 = fn_803C47CC(&sp8, 0, 0);
        result = r3;
        if (r3 == 0) {
            fn_803C70B8(arg0, (unsigned char)sp8);
        }
    }

    fn_803C4158(result);

    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }

    if (result == 0 || result == 0xB004) {
        if (lbl_805A120C != 0) {
            OSLockMutex(lbl_80563200);
        }

        temp = fn_803C7058(arg0);
        fn_803C68D8();
        result = fn_803C30C0(temp, arg1, 0);

        if (lbl_805A120C != 0) {
            OSUnlockMutex(lbl_80563200);
        }

        if (result != 0 && result != 0xB005) {
            if (lbl_805A120C != 0) {
                OSLockMutex(lbl_80563200);
            }

            fn_803C7058(arg0);
            if (fn_803C49B8() == 0) {
                fn_803C72A0(arg0);
            }

            if (lbl_805A120C != 0) {
                OSUnlockMutex(lbl_80563200);
            }
        }
    }

    return result;
}
