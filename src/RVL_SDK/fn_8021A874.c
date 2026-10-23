#include <types.h>
#pragma force_active on

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern s32 fn_8020E18C(void);
extern void fn_8020F5FC(void (*)(s32));
extern s32 fn_8020FED4(s32);
extern s32 fn_8020FF84(u8);
extern u8 lbl_805A0C72;
extern s32 lbl_805A0C74;

s32 fn_8021A874(void (*arg0)(s32)) {
    s32 enabled;
    s32 result;
    s32 level;
    u8 flag;

    if (fn_8020E18C() != 0) {
        return 0;
    }

    level = OSDisableInterrupts();
    flag = lbl_805A0C72;
    enabled = lbl_805A0C74 != 0;
    OSRestoreInterrupts(level);

    result = fn_8020FF84(flag) & 1;
    result &= fn_8020FED4(enabled);

    if (result != 0) {
        fn_8020F5FC(arg0);
    } else if (arg0 != 0) {
        arg0(2);
    }

    return result;
}
