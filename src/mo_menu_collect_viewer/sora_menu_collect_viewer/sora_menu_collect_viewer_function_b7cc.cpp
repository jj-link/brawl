#include <types.h>
#pragma force_active on

extern "C" void exit__6gfTaskFv(void*);

extern "C" s32 fn_6_B7CC(u8* self) {
    u8* task = *(u8**)(self + 0x140);
    if (*(s32*)(task + 0x104) == 3) {
        exit__6gfTaskFv(task);
        *(void**)(self + 0x140) = nullptr;
        return 1;
    }
    return *(s32*)(self + 0x128);
}
