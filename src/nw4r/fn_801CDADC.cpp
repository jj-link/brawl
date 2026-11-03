#include <types.h>
#pragma force_active on

extern "C" u8* fn_801CC2E4();
extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801D1210(void*, u8);

extern "C" void fn_801CDADC(u8* self, u8 val) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    self[0xbf] = val;
    if (val != 0) {
        self[0xc1] = 1;
    }
    s32 level = OSDisableInterrupts();
    u8 v = 0;
    if (self[0xbf] != 0) {
        v = 1;
    }
    if (self[0xc1] != 0) {
        v = 1;
    }
    if (v != self[0xc0]) {
        void* p = *(void**)(self + 0x7c0);
        if (p != nullptr) {
            fn_801D1210(p, v);
        }
        self[0xc0] = v;
    }
    OSRestoreInterrupts(level);
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
