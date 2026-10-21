#include <types.h>
#pragma force_active on

extern "C" int fn_800DCACC(void* object) {
    if (*reinterpret_cast<int*>(static_cast<u8*>(object) + 0x8c) == 0) {
        return 0;
    }
    return *reinterpret_cast<int*>(static_cast<u8*>(object) + 0xac);
}
