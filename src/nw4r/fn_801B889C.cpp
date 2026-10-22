#include <types.h>
#pragma force_active on

extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32);
extern "C" void* memset(void* dst, int c, u32 n);

extern "C" void fn_801B889C(u8* self, u32 a, u32 b, u32 c) {
    u32 level = OSDisableInterrupts();
    *(u32*)(self + 0x10) = a;
    *(u32*)(self + 0x14) = b;
    *(u32*)(self + 0x18) = c;
    memset(self + 0x1E, 0, 0x18);
    self[0x1C] = 1;
    OSRestoreInterrupts(level);
}
