#include <types.h>
#pragma force_active on

extern "C" {
void* fn_8004B1D0(void* arg0) {
    u8* p = *reinterpret_cast<u8**>(static_cast<u8*>(arg0) + 0x24);
    if (*reinterpret_cast<u16*>(p + 0x33e) == 0) {
        return 0;
    }
    return p + *reinterpret_cast<u16*>(p + 0x33c);
}
}
