#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern void *lbl_805A0E80;
extern OSMutex lbl_80532170;

extern void fn_801C92E4(int);
struct Obj;
extern void fn_8027A95C(struct Obj *);

void fn_8026F958(void)
{
    void *m;
    char *p = lbl_805A0E80;
    int i;

    if (*(int *)(p + 0x5D0) != 0) {
        m = &lbl_80532170;
        OSLockMutex(m);
        fn_801C92E4(*(int *)(p + 0x5D0));
        OSUnlockMutex(m);
    }

    i = 0;
    do {
        fn_8027A95C(*(struct Obj **)(p + 0x25C));
        i++;
        p += 4;
    } while (i < 4);
}
