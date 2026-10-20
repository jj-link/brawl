#include <types.h>
#pragma force_active on

extern "C" void fn_73_AAD8(void* self) {
    u32* p = (u32*)((u8*)self + 0x8);
    *p |= 0x02000000;
}
