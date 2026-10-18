#include <types.h>
#pragma force_active on

extern "C" void fn_104_1D020(void* object, u8 value) {
    *(static_cast<u8*>(object) + 0x175c0) = value;
}
