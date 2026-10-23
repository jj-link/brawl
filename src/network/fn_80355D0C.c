#pragma force_active on
extern int fn_80335238(void);
extern void OSInitMutex(void *);
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern unsigned char *fn_803353F4(int, int, int);
extern void fn_80335450(int, void *, int);
extern void fn_80335638(int, ...);
extern void fn_803571F4(int, int);
extern int fn_80358730(void);
extern int fn_8035874C(void *, void *);
extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern void OSCreateThread(void *, void *, int, void *, unsigned int, int, int);
extern void OSResumeThread(void *);
extern void fn_80355AFC(void);
extern void fn_80355834(void);
extern unsigned char lbl_8048DDD0[];
extern unsigned char lbl_805344B0[0x18];
extern int lbl_805A0FEC;
extern unsigned char *lbl_805A0FE8;
extern int lbl_8059F320;

int fn_80355D0C(char *arg0, char *arg1)
{
    unsigned char *base = lbl_8048DDD0;
    unsigned char *t;

    if (fn_80335238() != 0) {
        return 0;
    }
    OSInitMutex(lbl_805344B0);
    OSLockMutex(lbl_805344B0);
    if (lbl_805A0FEC != 0) {
        fn_803571F4(2, 0);
        OSUnlockMutex(lbl_805344B0);
        return 0;
    }
    lbl_805A0FEC = 2;
    OSUnlockMutex(lbl_805344B0);
    lbl_805A0FE8 = fn_803353F4(10, 0x54d8, 0x20);
    if (lbl_805A0FE8 == 0) {
        fn_803571F4(1, 0);
        return 0;
    }
    *(int *)(lbl_805A0FE8 + 0x48) = 0;
    memset(lbl_805A0FE8, 0, 0x54d8);
    *(void **)lbl_805A0FE8 = (void *)fn_80355AFC;
    strncpy((char *)lbl_805A0FE8 + 8, arg0, 0x1f);
    strncpy((char *)lbl_805A0FE8 + 0x28, arg1, 0x1f);
    if (fn_80358730() == 0) {
        fn_80335638(1, base + 0x2ac);
        fn_80335450(10, lbl_805A0FE8, 0);
        lbl_805A0FE8 = 0;
        return 0;
    }
    if (fn_8035874C(&lbl_8059F320, lbl_805A0FE8 + 0x4c) == 0) {
        fn_80335638(1, base + 0x2d4);
        fn_80335450(10, lbl_805A0FE8, 0);
        lbl_805A0FE8 = 0;
        return 0;
    }
    fn_80335638(1, base + 0x308);
    t = lbl_805A0FE8 + 0x51c0;
    OSCreateThread(t, (void *)fn_80355834, 0, t, 0x5000, 0x11, 0);
    OSResumeThread(lbl_805A0FE8 + 0x51c0);
    return 1;
}
