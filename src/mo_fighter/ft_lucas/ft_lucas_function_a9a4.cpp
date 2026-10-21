#include <types.h>
#pragma force_active on

extern "C" void* fn_27_197E94(void* self, u32 mode, u32 flag);
extern "C" void* fn_27_14DFE4(void* p, u32 a2, u32 a3, void* a4, void* a5, void* a6, void* a7, u32 a8, u32 a9);
extern "C" void fn_27_A78C0(void* self);
extern "C" void fn_27_1991F0(void* p, u32 v);
extern "C" void fn_27_CAF4C(void* p, u32 v);

extern "C" void* fn_114_A9A4(char* self, u32 a, u32 b, u32 c) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a, (u8)b, self + 0x220, self + 0x94, self + 0x78, self, c, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
