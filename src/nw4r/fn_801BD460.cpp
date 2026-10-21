#include <types.h>
#pragma force_active on

extern "C" void fn_801BD460(void* self, u32 value) {
    *reinterpret_cast<u32*>(static_cast<u8*>(self) + 0xA0) = value;
    *reinterpret_cast<u8*>(static_cast<u8*>(self) + 0x9C) = 1;
}
