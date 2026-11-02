extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_803C4640(void);
extern int lbl_805A120C;
extern int lbl_805A1208;
extern unsigned char lbl_80563200[0x18];

#pragma force_active on
void fn_803C2FE4(void)
{
    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    if (lbl_805A1208 != 0) {
        fn_803C4640();
        lbl_805A1208 = 0;
    }
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
}
