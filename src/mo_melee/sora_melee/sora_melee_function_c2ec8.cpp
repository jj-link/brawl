#include <types.h>
#pragma force_active on

extern "C" void fn_27_C2EC8(void* self, u32 value) {
    *reinterpret_cast<u32*>(static_cast<u8*>(self) + 8) = value;
    *reinterpret_cast<u8*>(static_cast<u8*>(self) + 0x20) = 1;
}
