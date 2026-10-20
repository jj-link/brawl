#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A70A4(void* arg) {
    u32* ptr = reinterpret_cast<u32*>(static_cast<u8*>(arg)) + 2;
    *ptr &= ~0x00080000;
}
