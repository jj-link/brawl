#include <types.h>
#pragma force_active on

extern "C" void fn_27_389DFC(void* p) {
    u32* field = reinterpret_cast<u32*>(reinterpret_cast<u8*>(p) + 8);
    *field |= 0x80000;
}
