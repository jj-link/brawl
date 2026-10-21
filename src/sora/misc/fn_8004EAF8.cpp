#include <types.h>
#pragma force_active on

extern "C" int fn_8004EAF8(void* arg0) {
    u32* p = (u32*)arg0;
    if (p[0] == 0x14U) {
        if (p[1] == 0xC660U) {
            return 1;
        }
    }
    return 0;
}
