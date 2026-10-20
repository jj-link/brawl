#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A26E0(void* p) {
    u32* field = (u32*)((char*)p + 8);
    *field |= 0x00080000;
}
