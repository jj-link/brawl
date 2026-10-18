#include <types.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_18D0;
extern "C" char lbl_27_data_2BE40[];
extern "C" void fn_27_14B700(void* self);

extern "C" {
void* fn_27_14B5F8(void* self, u32 p2) {
    u8* p = (u8*)self;
    p[4] = 0;
    *(float*)(p + 8) = lbl_27_rodata_18D0;
    *(float*)(p + 0xC) = lbl_27_rodata_18D0;
    *(void**)p = (void*)lbl_27_data_2BE40;
    *(u32*)(p + 0x14) = p2;
    *(u32*)(p + 0x538) = 0;
    *(float*)(p + 0x690) = lbl_27_rodata_18D0;
    fn_27_14B700(self);
    return self;
}
}
