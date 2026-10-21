#pragma force_active on
typedef void (*Callback)(void);

typedef struct NetworkState {
    unsigned char pad0[4];
    Callback callback;
    unsigned char pad8[0x40];
    int flag;
    unsigned char pad4C[0x5174];
    unsigned char thread[1];
} NetworkState;

extern int lbl_805A0FEC;
extern unsigned char lbl_805344B0[0x18];
extern NetworkState *lbl_805A0FE8;

extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern int OSJoinThread(void *, void **);
extern void fn_80335450(int, void *, int);
extern void fn_80355CB0(void);
extern void fn_803557D0(void);
extern void fn_80357170(Callback);
extern void fn_803571F4(int, int);

int fn_80355FAC(void)
{
    Callback callback;

    if (lbl_805A0FEC == 0) {
        fn_803571F4(2, 0);
        return 0;
    }

    OSLockMutex(lbl_805344B0);
    if (lbl_805A0FEC == 0) {
        fn_803571F4(2, 0);
        OSUnlockMutex(lbl_805344B0);
        return 0;
    }

    lbl_805A0FEC = 2;
    OSUnlockMutex(lbl_805344B0);
    lbl_805A0FE8->callback = fn_80355CB0;

    if (lbl_805A0FE8->flag == 0) {
        OSJoinThread(lbl_805A0FE8->thread, 0);
        callback = lbl_805A0FE8->callback;
        fn_80335450(10, lbl_805A0FE8, 0);
        lbl_805A0FE8 = 0;
        if (callback != 0) {
            callback();
        }
    } else {
        fn_80357170(fn_803557D0);
    }

    return 1;
}
