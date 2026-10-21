#include <types.h>
#pragma force_active on

extern "C" void fn_27_385C0C(void* obj) {
    u32* flags = (u32*)((u8*)obj + 8);
    *flags &= ~0x2;
}
