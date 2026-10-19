#include <types.h>
#pragma force_active on

extern "C" int fn_24_6B4(void* object) {
    if (*reinterpret_cast<int*>(static_cast<char*>(object) + 0x1d8) >= 60) {
        if (*reinterpret_cast<int*>(static_cast<char*>(object) + 0x1d4) == 6) {
            return 1;
        }
    }
    return 0;
}
