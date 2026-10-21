#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_197E94(void* self, u32 mode, u32 extra);
void* fn_27_14DFE4(void* p, u32 a2, u32 a3, void* a4, void* a5, void* a6, void* a7, u32 a8, u32 a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, u32 v);
void fn_27_CAF4C(void* p, u32 v);

void* fn_103_8C14(u8* self, u32 a1, u32 a2, u32 a3) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a1, a2 & 0xFF, self + 0x220, self + 0x94, self + 0x78, self, a3, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
}
