#include <types.h>
#pragma force_active on

extern void OSCancelAlarm(void *alarm);
extern void fn_801D6E14(void *alarm, void *arg);
extern void fn_801D68F8(void *alarm, s64 tick, void *handler);
extern s32 *fn_803CD2A8(void);
extern s32 fn_803CD32C(void);
extern s32 fn_803CD3F4(void);
extern void fn_803CD410(s32 arg0);
extern void *fn_803CD324(void);
extern s32 fn_803CE570(void);
extern void fn_803CE574(void);
extern void fn_803CFBE4(s32 a, s32 b);
extern void fn_803D48E0(s32 arg0);
extern void fn_803D5340(void);

void fn_803D4950(void) {
    s32 *p;
    s32 *q;
    s32 v;

    p = fn_803CD2A8();
    switch (fn_803CD32C()) {
    case 0:
        q = fn_803CD2A8();
        if (fn_803CE570() == 0) {
            fn_803CE574();
        }
        v = q[0];
        q[24] = v;
        q[25] = 0x1F1E0;
        q[26] = v;
        q[27] = 0;
        *(s16 *)&q[28] = 0;
        q[42] = (s32)(void *)fn_803D48E0;
        OSCancelAlarm(&q[30]);
        fn_801D6E14(&q[30], &q[24]);
        fn_801D68F8(&q[30], (s64)(((*(u32 *)0x800000F8 >> 2) / 1000) * 0x13), (void *)fn_803D5340);
        return;
    case 2:
        switch (fn_803CD3F4()) {
        case -4:
            fn_803CD410(3);
            break;
        default:
        case -5:
        case -15:
            *(s32 *)((char *)fn_803CD324() + 0x1B40) = 3;
            fn_803CD410(1);
            break;
        }
        fn_803CFBE4(0, p[3]);
        return;
    default:
    case 1:
        fn_803CD410(1);
        fn_803CFBE4(0, p[3]);
        return;
    }
}
