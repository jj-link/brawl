#include <types.h>
#pragma force_active on

extern "C" void fn_27_2EBA08(void* self) {
    u32* ptr = reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 8);
    *ptr |= 0x00400000;
}
