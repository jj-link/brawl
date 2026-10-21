#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_197E94(void* self, u32 mode, u32 unused);
void* fn_27_14DFE4(void* p, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* self, u32 value);
void* fn_27_CAF4C(char* self, u32 value);

void* fn_107_A3CC(void* self, u32 arg2, u32 arg3, u32 arg4) {
    char* p = (char*)self;
    fn_27_197E94(p, 1, 0);
    fn_27_14DFE4(p + 0x10, arg2, arg3 & 0xFF, (u32)(p + 0x220),
                 (u32)(p + 0x94), (u32)(p + 0x78), (u32)p, arg4, 8);
    fn_27_A78C0(p + 0x78);
    fn_27_1991F0(p + 0x94, 0);
    fn_27_CAF4C(p + 0x220, 0);
    return self;
}
}
