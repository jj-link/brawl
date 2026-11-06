#include <types.h>
#pragma force_active on
extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void fn_801D1C3C(u8*);

extern "C" void fn_801D3078(u8* self) {
    s32 level;
    u8* node;
    level = OSDisableInterrupts();
    u8** head = (u8**)(self + 8);
    node = *head;
    while (node != (u8*)head) {
        u8* current = node;
        node = *(u8**)node;
        fn_801D1C3C(current - 0x124);
    }
    OSRestoreInterrupts(level);
}