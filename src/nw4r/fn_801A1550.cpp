#include <types.h>
#pragma force_active on
extern "C" void fn_801EC158(void* p);

extern "C" void fn_801A1550(unsigned char* self) {
    fn_801EC158(self + 0x8);
    fn_801EC158(self + 0x38);
    fn_801EC158(self + 0x68);
    *(u8*)(self + 0x6) = 0;
    *(u8*)(self + 0x5) = 0;
    *(u8*)(self + 0x4) = 0;
}
