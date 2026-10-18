#include <types.h>
#pragma force_active on

extern "C" void fn_112_16AB0(void* object, u8 value) {
    *(static_cast<u8*>(object) + 0x16090) = value;
}
