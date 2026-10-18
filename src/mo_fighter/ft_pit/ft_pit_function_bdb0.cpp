#include <types.h>
#pragma force_active on

extern "C" void fn_112_BDB0(void* object, u8 value) {
    *(static_cast<u8*>(object) + 0x21580) = value;
}
