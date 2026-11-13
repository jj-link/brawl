#include <types.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern void *lbl_805A0E80;
extern s32 fn_801D6E1C(void);
extern s32 fn_80218D54(void);
extern s32 fn_80218D58(void);
extern void fn_801D6E14(OSAlarm *, s32);
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);

void fn_80273254(OSAlarm *alarm, OSContext *ctx) {
    u8 *temp_r31;
    s32 temp_r3;
    s32 var_r29;

    temp_r31 = (u8 *)lbl_805A0E80;
    temp_r3 = fn_801D6E1C();
    var_r29 = 0;
    if (temp_r3 == 0) {
        if (fn_80218D54() != 0) {
            temp_r31[0x89] = 1;
            var_r29 = 1;
        }
    } else if (fn_80218D58() != 0) {
        var_r29 = 1;
    }
    if (var_r29 == 0) {
        OSCancelAlarm((OSAlarm *)(temp_r31 + 0x598));
        fn_801D6E14((OSAlarm *)(temp_r31 + 0x598), temp_r3);
        fn_801D68F8((OSAlarm *)(temp_r31 + 0x598),
                    (OS_BUS_CLOCK_SPEED / 4 / 1000) * 100, fn_80273254);
    }
}