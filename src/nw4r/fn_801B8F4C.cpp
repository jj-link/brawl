#include <types.h>
#pragma force_active on

struct Obj {
    void* unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32 level);

extern "C" s32 fn_801B8F4C(Obj* arg0, u32 arg1, u32 arg2) {
    s32 level = OSDisableInterrupts();
    if (arg0->unk0 == nullptr) {
        OSRestoreInterrupts(level);
        return 0;
    }
    u32 temp = arg0->unk10;
    u32 result = 0;
    if (temp != 0) {
        s32 flag = (arg1 <= temp && temp <= arg2) ? 1 : 0;
        if (flag != 0) {
            result = 1;
        }
    }
    OSRestoreInterrupts(level);
    return result;
}
