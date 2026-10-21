#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_197E94(void* self, u32 a, u32 b);
void fn_27_14DFE4(void* p, u32 a2, u32 a3, void* a4, void* a5, void* a6, void* a7, u32 a8, u32 a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, u32 a2);
void fn_27_CAF4C(void* self, u32 a2);
}

extern "C" void* fn_112_9128(void* self, u32 a2, u32 a3, u32 a4) {
    char* p = (char*)self;
    fn_27_197E94(p, 1, 0);
    fn_27_14DFE4(p + 0x10, a2, a3 & 0xFF, p + 0x220, p + 0x94, p + 0x78, self, a4, 8);
    fn_27_A78C0(p + 0x78);
    fn_27_1991F0(p + 0x94, 0);
    fn_27_CAF4C(p + 0x220, 0);
    return self;
}
