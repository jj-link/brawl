#include <types.h>
#pragma force_active on

extern "C" {
void fn_800BF830(void* p);
void exit__6gfTaskFv(void* self);
void* fn_800BEEB8(s32 a1, s32 a2, s32 a3, void* a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12);

void fn_800DCAE8(void* self, s32 unused, s32 a, s32 b) {
    u8* p = (u8*)self;
    s32 flag = (b != 0);
    s32 r30 = *(s32*)(p + 0x90);
    void* task = *(void**)(p + 0xB0);
    if (task != nullptr) {
        fn_800BF830(task);
        exit__6gfTaskFv(*(void**)(p + 0xB0));
        *(void**)(p + 0xB0) = nullptr;
    }
    *(void**)(p + 0xB0) = fn_800BEEB8(flag, r30, a, p + 0x3C, *(s32*)(p + 0x8), 0x60, 0, 0x2A, 0x2A, 1, 1, 0xF0);
}
}
