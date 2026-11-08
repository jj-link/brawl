#include <revolution/OS/OSTime.h>
#pragma force_active on

extern "C" {
extern void fn_801E1D80(s64, OSCalendarTime*);
extern u64 fn_8014F9C8(void);
extern s32 fn_8014FA60(void);

s32 fn_8014E070(void) {
    OSCalendarTime sp30;
    OSCalendarTime sp8;
    s32 var_r31;

    var_r31 = 0;
    fn_801E1D80(OSGetTime(), &sp8);
    fn_801E1D80(fn_8014F9C8(), &sp30);
    if (sp30.year == sp8.year && sp30.yday == sp8.yday) {
        var_r31 = fn_8014FA60();
    }
    return var_r31;
}
}
