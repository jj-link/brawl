#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern int fn_803C35A8(int *, int);
extern void fn_803C4158(int);
extern int fn_803C5558(int, int);
extern int fn_803C5644(int, int, int);
extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];

int fn_803C374C(int arg0, int arg1)
{
    int index = -1;
    int value;
    int result;

    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    value = fn_803C35A8(&index, arg0);
    if (value == 0) {
        fn_803C4158(0xB003);
        if (lbl_805A120C != 0) {
            OSUnlockMutex(lbl_80563200);
        }
        return 0;
    }
    if (index != -1) {
        result = fn_803C5644(index, value, arg1);
    } else {
        result = fn_803C5558(value, arg1);
    }
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
    return result;
}