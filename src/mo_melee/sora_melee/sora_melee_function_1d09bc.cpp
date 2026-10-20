#include <types.h>
#pragma force_active on

extern "C" void fn_27_1D09BC(void* self) {
    u32* flags = reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 8);
    *flags |= 0x80000;
}
