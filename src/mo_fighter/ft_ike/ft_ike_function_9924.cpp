#include <types.h>
#pragma force_active on

extern "C" void fn_119_9924(void* self, u32 mask, u32 index) {
    u32* arr = *(u32**)((char*)self + 0x1c);
    arr[index] |= mask;
}
