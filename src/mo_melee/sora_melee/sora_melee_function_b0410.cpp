#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_B0410(void* obj) {
    s32* p = (s32*)((u8*)obj + 0x8);
    return *p >> 27;
}
}
