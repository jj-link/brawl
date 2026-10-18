#include <types.h>
#pragma force_active on

extern "C" void fn_95_CFFC(void* object, u8 value) {
    *(static_cast<u8*>(object) + 0x19DA0) = value;
}
