#include <types.h>
#pragma force_active on

extern "C" void fn_110_987C(u8* work, u32 index) {
    u32* arr = *(u32**)(work + 0x1c);
    arr[index] = 0;
}
