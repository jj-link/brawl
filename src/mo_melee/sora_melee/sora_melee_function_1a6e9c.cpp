#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A6E9C(void* self) {
    u32* ptr = reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 0x8);
    *ptr |= 0x2;
}
