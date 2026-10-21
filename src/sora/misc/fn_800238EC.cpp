#include <types.h>
#pragma force_active on

extern "C" void* fn_800238EC(u8* arg0) {
    if (arg0[7] == 0xF0) {
        arg0[7] = 0;
    }
    arg0 = arg0 + (arg0[7] * 8);
    return *(void**)(arg0 + 0x10);
}
