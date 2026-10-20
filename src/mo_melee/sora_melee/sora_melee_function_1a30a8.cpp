#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A30A8(void* self) {
    u32* ptr = reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 8);
    *ptr |= 0x400000;
}
