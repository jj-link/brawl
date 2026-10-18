#include <types.h>
#pragma force_active on

extern "C" void fn_93_CBB8(void* object, u8 value) {
    *(static_cast<u8*>(object) + 0x11bec) = value;
}
