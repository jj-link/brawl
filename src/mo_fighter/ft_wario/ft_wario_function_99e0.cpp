#include <types.h>
#pragma force_active on

extern "C" void fn_110_99E0(u8* self, u32 value, u32 index) {
    u32* arr = *(u32**)(self + 0xc);
    arr[index] = value;
}
