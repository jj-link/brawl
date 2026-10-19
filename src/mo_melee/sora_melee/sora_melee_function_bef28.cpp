#include <types.h>
#pragma force_active on

extern "C" void fn_27_C0FD8(void* p);

extern "C" void fn_27_BEF28(u8* self) {
    fn_27_C0FD8(self + 0x30);
    fn_27_C0FD8(self + 0xB8);
    *(u8*)(self + 0x14E) = 1;
    *(u32*)(self + 0x144) = 0;
    *(u8*)(self + 0x150) = 0;
}
