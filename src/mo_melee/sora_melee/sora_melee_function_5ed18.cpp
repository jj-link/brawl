#include <types.h>

extern "C" void fn_27_B15BC(void*, u32);

#pragma force_active on
extern "C" void fn_27_5ED18(void* self) {
    fn_27_B15BC(reinterpret_cast<u8*>(self) + 0x44, 1);
}
