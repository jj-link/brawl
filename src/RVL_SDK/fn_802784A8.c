#include <types.h>
#pragma force_active on
extern void OSCancelAlarm(void *);
extern void fn_801D68F8(void *, s64, void *);
extern void fn_801D6E14(void *, int);
extern int fn_80218D58(void);
extern void fn_80218D5C(void *);
extern void fn_8027AC0C(void *);
extern void fn_80273254(void);
void fn_802784A8(void *arg0) {
    u8 *self = (u8 *)arg0;
    u8 *p;
    int r3;
    int i;
    int v;
    float f;
    void (*fp)(int, int);
    if (self[0x91] != 0) return;
    self[0x91] = 1;
    p = self;
    for (i = 0; i < 4; i++) {
        fn_8027AC0C(*(void **)(p + 0x25C));
        p += 4;
    }
    r3 = *(int *)(self + 0x10);
    self[0x8C] = 0;
    self[0x8D] = 0;
    self[0x8F] = 0;
    self[0x90] = 0;
    switch (r3) {
    case 0:
        self[0x8C] = 1;
    case 1:
        self[0x8D] = 1;
        break;
    case 3:
    case 5:
    case 6:
    case 7:
        goto B;
    default:
        break;
    }
    goto tail;
B:
    if ((r3 == 3 && *(int *)(self + 0x14) == 5) || (r3 == 5 && self[0x89] == 0)) {
        OSCancelAlarm(self + 0x598);
        fn_80218D5C(*(void **)(self + 0x1BC));
    } else if (self[0x8A] == 0 && r3 > 3) {
        self[0x8F] = 1;
        if (fn_80218D58() == 0) {
            OSCancelAlarm(self + 0x598);
            fn_801D6E14(self + 0x598, 1);
            fn_801D68F8(self + 0x598, (s64)(((*(u32 *)0x800000F8 >> 2) / 1000) * 100), (void *)fn_80273254);
        }
    } else {
        fn_80218D5C(*(void **)(self + 0x1BC));
    }
    self[0x90] = 1;
tail:
    *(int *)(self + 0x10) = 0x13;
    v = *(int *)(self + 0x408);
    *(int *)(self + 0x40C) = 1;
    *(int *)(self + 0xB0) = 2;
    f = (float)v;
    *(float *)(self + 0x760) = f;
    fp = *(void (**)(int, int))(*(u8 **)(self + 0x4) + 0x14);
    if (fp != 0) fp(3, (int)f);
}