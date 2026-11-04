#pragma force_active on
#include <types.h>

extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void fn_801BAD38(void*, s32);

extern const double lbl_805A3468;
extern const float lbl_805A3458;
extern const float lbl_805A345C;
extern const float lbl_805A3460;

extern "C" void fn_801B9894(void* arg0, s32 arg1, f32 farg0) {
    s32 level = OSDisableInterrupts();
    if (*(s32*)arg0 == 0) {
        OSRestoreInterrupts(level);
        return;
    }

    if (arg1 == 5) {
        f32 temp = (farg0 * (f32)*(s32*)((char*)arg0 + 0x18)) / lbl_805A3458;
        if (temp > lbl_805A345C) {
            arg1 = 2;
        } else if (temp > lbl_805A3460) {
            arg1 = 3;
        } else {
            arg1 = 4;
        }
    }

    fn_801BAD38(arg0, arg1);
    OSRestoreInterrupts(level);
}
