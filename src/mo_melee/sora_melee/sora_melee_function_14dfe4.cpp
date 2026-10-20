#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_A34D4(void* self, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
void fn_27_A78C0(void* self);
extern u8 lbl_27_data_2D0F8[];
}

extern "C" void* fn_27_14DFE4(void* p, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9) {
    u8* self = (u8*)p;
    fn_27_A34D4(self, a2, a3, a4, a5, a6, a7, a8, a9);
    u8* vt = lbl_27_data_2D0F8;
    *(u8**)(self + 0x0) = vt;
    *(u8**)(self + 0x8) = vt + 0x88;
    *(u8**)(self + 0xC) = vt + 0x94;
    *(u8**)(self + 0x18) = vt + 0xA8;
    *(u8**)(self + 0x24) = vt + 0xB8;
    fn_27_A78C0(self + 0x4c);
    return self;
}
