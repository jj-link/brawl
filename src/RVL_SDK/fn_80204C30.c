#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

u32 fn_80204C30(void *p, s32 alignment)
{
    void *start;
    void *end;
    u32 result;
    BOOL level;
    alignment = __abs(alignment);
    level = OSDisableInterrupts();
    start = (void *)(((u32)*(void **)((char *)p + 0x3c) + alignment - 1) & ~(alignment - 1));
    end = *(void **)((char *)p + 0x40);
    if (start > end)
        result = 0;
    else
        result = (u32)end - (u32)start;
    OSRestoreInterrupts(level);
    return result;
}