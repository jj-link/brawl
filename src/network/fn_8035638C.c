#pragma force_active on
typedef unsigned char OSMutex[0x18];

extern int fn_80335238(void);
extern void fn_803571F4(int, int);
extern int fn_80357378(void);
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);

extern unsigned char lbl_805344B0[0x18];
extern int lbl_805A0FEC;

int fn_8035638C(void)
{
    if (fn_80335238() != 0) {
        return 0;
    }
    OSLockMutex(lbl_805344B0);
    if (lbl_805A0FEC != 2) {
        fn_803571F4(2, 0);
        OSUnlockMutex(lbl_805344B0);
        return 0;
    }
    OSUnlockMutex(lbl_805344B0);
    if (fn_80357378() != 0) {
        return 1;
    }
    fn_803571F4(2, 0);
    return 0;
}
