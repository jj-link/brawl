#include <types.h>
#pragma force_active on

extern "C" {
extern u32 lbl_27_bss_31F8;
void fn_27_143E28(u32 a, u32 b);
void fn_27_11EF50(u8* self, s32 index);
}

extern "C" void fn_27_11EF50(u8* self, s32 index) {
    s32* entry = (s32*)(self + index * 0x54);
    fn_27_143E28(lbl_27_bss_31F8, entry[2]);
    *(s32*)(self + 4) = 1;
}
