#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_197E94(char*, u32, u32);
void* fn_27_14DFE4(u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_27_A78C0(char*);
void fn_27_1991F0(char*, u32);
void* fn_27_CAF4C(char*, u32);
}

extern "C" char* fn_109_8134(char* self, u32 a2, u32 a3, u32 a4) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4((u32)(self + 0x10), a2, a3 & 0xFF, (u32)(self + 0x220), (u32)(self + 0x94), (u32)(self + 0x78), (u32)self, a4, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
