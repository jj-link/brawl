#include <revolution/OS/OSTime.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_8014BF30(char* self, int a, int b) {
    *(int*)(self + 0x3430) = a;
    *(int*)(self + 0x3434) = b;
    *(u32*)(self + 0x3438) = OSGetTick();
}
