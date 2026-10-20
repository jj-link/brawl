#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1D0(void* a, int b);
extern "C" void fn_8015C144(void* a, void* b);

extern "C" {
u32 fn_27_5013C(char* self) {
    void* r = fn_8015C1D0(self + 0xA8, 0);
    fn_8015C144(self + 0xA8, r);
    return ((u32*)r)[0x28 / 4] >> 24;
}
}
