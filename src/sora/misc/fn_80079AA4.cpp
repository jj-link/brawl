#include <types.h>
#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801DEF60(void*);

extern "C" void fn_80079AA4(unsigned char* self, s32 a, s32 b, s32 c) {
    OSLockMutex(self + 0x340);
    if (*(u32*)(self + 0xcc8) < 0x95) {
        *(s32*)(self + ((*(u32*)(self + 0xcc8)) << 4) + 0x368) = 1;
        *(s32*)(self + ((*(u32*)(self + 0xcc8)) << 4) + 0x370) = a;
        *(s32*)(self + ((*(u32*)(self + 0xcc8)) << 4) + 0x36c) = b;
        *(s32*)(self + ((*(u32*)(self + 0xcc8)) << 4) + 0x374) = c;
        *(u32*)(self + 0xcc8) = *(u32*)(self + 0xcc8) + 1;
    }
    OSUnlockMutex(self + 0x340);
    fn_801DEF60(self + 0x358);
}
