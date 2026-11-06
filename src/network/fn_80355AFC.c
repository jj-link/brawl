#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_80335638(int, ...);
extern void fn_803571F4(int, int);
extern unsigned char lbl_8048DDD0[];
extern unsigned char lbl_805344B0[0x18];
extern int lbl_805A0FEC;
extern int lbl_805A0FF0;

void fn_80355AFC(int arg0, int arg1, int arg2) {
    unsigned char *base = lbl_8048DDD0;

    if (arg1 != 0) {
        fn_803571F4(arg1, arg2);
    }
    switch (arg0) {
    case 1:
        fn_80335638(1, base + 0x198);
        break;
    case 2:
        fn_80335638(1, base + 0x1B4);
        break;
    case 3:
        fn_80335638(1, base + 0x1D0);
        break;
    case 0:
        fn_80335638(1, base + 0x1E0);
        break;
    }
    switch (arg1) {
    case 0:
        fn_80335638(1, base + 0x1F4);
        break;
    case 1:
        fn_80335638(1, base + 0x204);
        break;
    case 3:
        fn_80335638(1, base + 0x218);
        break;
    case 4:
        fn_80335638(1, base + 0x228);
        break;
    case 7:
        fn_80335638(1, base + 0x23C);
        break;
    case 6:
        fn_80335638(1, base + 0x250);
        break;
    }
    OSLockMutex(lbl_805344B0);
    lbl_805A0FEC = 3;
    lbl_805A0FF0 = arg0;
    if (arg1 != 0) {
        fn_80335638(1, base + 0x268, arg2);
        lbl_805A0FEC = 4;
    }
    OSUnlockMutex(lbl_805344B0);
}
