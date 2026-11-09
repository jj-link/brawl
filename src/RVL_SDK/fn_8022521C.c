#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern void *lbl_804F6810[];
extern s32 fn_8021E1E8(void *, s32, s32, s32, void (*)(s32, s32));

s32 fn_8022521C(s32 index, s32 arg1, s32 arg2, s32 arg3, void (*callback)(s32, s32)) {
    char *state;
    s32 ready;
    s32 result;
    s32 temp;
    BOOL en;

    state = (char *)lbl_804F6810[index];
    en = OSDisableInterrupts();
    result = *(s32 *)(state + 0x8bc);
    ready = *(s32 *)(state + 0x8dc);
    OSRestoreInterrupts(en);
    if (result != -1) {
        if (ready == 0) {
            result = -2;
        } else {
            temp = fn_8021E1E8(state + 0x160, arg1, arg2, arg3, callback);
            result = (temp != 0) ? 0 : -2;
        }
    }
    if (result != 0 && callback != 0) {
        callback(index, result);
    }
    return result;
}
