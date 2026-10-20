#include <types.h>
#pragma force_active on

extern "C" void fn_1_1005C(u8* self) {
    *(s32*)(self + 0x10) = 2;
    *(s32*)(self + 0x14) = 0;
}
