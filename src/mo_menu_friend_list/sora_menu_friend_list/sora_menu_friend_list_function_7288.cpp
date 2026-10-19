#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);
}

extern "C" s32 fn_14_7288(void* self) {
    u8* p = (u8*)self;
    void* task = *(void**)(p + 0x24EC);
    if (*(s32*)((u8*)task + 0x104) == 3) {
        exit__6gfTaskFv(task);
        *(void**)(p + 0x24EC) = nullptr;
        return 8;
    }
    return *(s32*)(p + 0x24C4);
}
