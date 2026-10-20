#include <types.h>
#pragma force_active on

extern "C" void fn_27_2961B8(void* self) {
    u32* field = (u32*)((u8*)self + 8);
    *field &= ~(1 << 13);
}
