#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A3EE0(void* p) {
    u32* val = reinterpret_cast<u32*>((u8*)p + 0x8);
    *val |= 0x2;
}
