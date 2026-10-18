#include <types.h>
#pragma force_active on

extern "C" void fn_104_A9E4(void* self, u32 index) {
    u32* arr = *(u32**)((char*)self + 0x1c);
    arr[index] = 0;
}
