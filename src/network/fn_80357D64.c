#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern int fn_8035786C(int **, void **, const char *, void *, int);
extern int fn_80395FA0(void *);
extern void fn_803571F4(int, int);
extern const char lbl_80415764[];
extern unsigned char lbl_80534598[];
extern OSMutex lbl_805344D8;
extern void *lbl_805A1004;

int fn_80357D64(int arg0)
{
    int *spC;
    void *sp8;
    void *request;
    int result;

    if (fn_8035786C(&spC, &sp8, lbl_80415764, lbl_80534598, 0x80) == 0) {
        return 0;
    }
    spC[0] = 1;
    spC[3] = arg0;
    request = sp8;
    OSLockMutex(&lbl_805344D8);
    if (fn_80395FA0(request) != 0) {
        fn_803571F4(3, 0);
        OSUnlockMutex(&lbl_805344D8);
        result = 0;
    } else {
        lbl_805A1004 = request;
        OSUnlockMutex(&lbl_805344D8);
        result = 1;
    }
    if (result == 0) {
        return 0;
    }
    return 1;
}
