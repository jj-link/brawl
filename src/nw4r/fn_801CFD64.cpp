#include <types.h>
#pragma force_active on
extern "C" s32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(s32);
extern "C" s32 fn_801CFD64(u8* arg0) {
    s32 level = OSDisableInterrupts();
    s32 t = OSDisableInterrupts();
    s32 result;
    if (*(s32*)(arg0 + 0x18) == 0) {
        OSRestoreInterrupts(t);
        result = 0;
    } else {
        s32 value = *(s32*)(arg0 + 0x1C);
        OSRestoreInterrupts(t);
        result = value - 4;
    }
    if (result != 0) {
        OSRestoreInterrupts(level);
        return result;
    }
    t = OSDisableInterrupts();
    s32 result2;
    if (*(s32*)(arg0 + 0xC) == 0) {
        OSRestoreInterrupts(t);
        result2 = 0;
    } else {
        s32 value = *(s32*)(arg0 + 0x10);
        OSRestoreInterrupts(t);
        result2 = value - 4;
    }
    if (result2 != 0) {
        OSRestoreInterrupts(level);
        return result2;
    }
    t = OSDisableInterrupts();
    s32 result3;
    if (*(s32*)(arg0 + 0x0) == 0) {
        OSRestoreInterrupts(t);
        result3 = 0;
    } else {
        s32 value = *(s32*)(arg0 + 0x4);
        OSRestoreInterrupts(t);
        result3 = value - 4;
    }
    if (result3 != 0) {
        OSRestoreInterrupts(level);
        return result3;
    }
    OSRestoreInterrupts(level);
    return 0;
}