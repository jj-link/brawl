#include <types.h>
#pragma force_active on

extern "C" void fn_27_23A410(void* self);
extern u32 lbl_1_data_128;

extern "C" void fn_1_9FC(void* self) {
    fn_27_23A410(self);
    u8* p = (u8*)self;
    *(u32*)(p + 0x8) = lbl_1_data_128;
    *(u32*)(p + 0xC) = 0;
    *(u8*)(p + 0x12) = 0;
}
