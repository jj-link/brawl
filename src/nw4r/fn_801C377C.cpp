#include <types.h>
#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801C5160(void*, u8);
extern "C" u8* fn_801CC2E4();

extern "C" void fn_801C377C(u8* self, u8 val) {
    u8* p = self;
    OSLockMutex(fn_801CC2E4() + 0x354);
    self[0x8e] = val;
    s32 i = 0;
    do {
        void* v;
        if (i > 15) {
            v = nullptr;
        } else {
            v = *(void**)(p + 0xb8);
        }
        if (v != nullptr) {
            fn_801C5160(v, val);
        }
        i += 1;
        p += 4;
    } while (i < 16);
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
