#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern int fn_803C35A8(int *, int);
extern void fn_803C4158(int);
extern int fn_803C63FC(int, int, int);
extern int fn_803C64EC(int, int, int, int);

extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];

int fn_803C3DE0(int arg0, int arg1, int arg2)
{
    int index = -1;
    int value;
    int result;

    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }

    value = fn_803C35A8(&index, arg1);
    if (value == 0) {
        fn_803C4158(0xB003);
        if (lbl_805A120C != 0) {
            OSUnlockMutex(lbl_80563200);
        }
        return 0xB003;
    }

    if (index != -1) {
        result = fn_803C64EC(arg0, index, value, arg2);
    } else {
        result = fn_803C63FC(arg0, value, arg2);
    }

    fn_803C4158(result);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }

    return result;
}
