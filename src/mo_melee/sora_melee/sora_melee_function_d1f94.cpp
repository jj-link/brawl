#include <types.h>
#pragma force_active on

extern "C" void fn_27_D1F94(void* p) {
    u32* flags = (u32*)((char*)p + 0x8);
    *flags &= ~0x00080000;
}
