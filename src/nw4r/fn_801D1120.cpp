#include <types.h>
#pragma force_active on

extern "C" void fn_801D1120(void* p) {
    u8* ptr = (u8*)p;
    ptr[0xad] = 1;
    ptr[0xaf] = 0;
    ptr[0xb1] = ptr[0xb1] | 1;
}
