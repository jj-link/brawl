#include <types.h>
#pragma force_active on

extern "C" int fn_18_F78(void* object) {
    if (static_cast<u8*>(object)[0x288] != 0) {
        if (*reinterpret_cast<s32*>(static_cast<u8*>(object) + 0x27c) == 5) {
            return 1;
        }
    }
    return 0;
}
