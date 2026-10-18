#include <types.h>

#pragma force_active on
extern "C" void fn_105_1852C(void* self, u32 value) {
    u32* ptr = reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 8);

    ptr[2] = value;
    ptr[1] = value;
    ptr[0] = value;
}
