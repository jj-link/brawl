#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E7E58(void* p) {
    u32* field = reinterpret_cast<u32*>(static_cast<u8*>(p) + 8);
    *field |= 0x80000;
}
