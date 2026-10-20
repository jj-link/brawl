#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_C102C(void* obj) {
    u8* p = (u8*)obj;
    if (p[0x34] == 1 || p[0x70] == 1) {
        return 1;
    }
    return 0;
}
