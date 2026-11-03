#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern int fn_803C35A8(int *, int);
extern void fn_803C4158(int);
extern int fn_803C61FC(int *, int);
extern int fn_803C62DC(int *, int, int);
extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];

int fn_803C3CF8(int arg0) {
    int spC[5];
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
        result = 0xB003;
    } else {
        if (index != -1) {
            result = fn_803C62DC(spC, index, value);
        } else {
            result = fn_803C61FC(spC, value);
        }
        fn_803C4158(result);
        if (lbl_805A120C != 0) {
            OSUnlockMutex(lbl_80563200);
        }
    }

    if (result == 0) {
        return spC[0];
    }
    return -1;
}
