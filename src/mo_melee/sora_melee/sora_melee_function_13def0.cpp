#include <types.h>
#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 type);
extern "C" void fn_27_8CE54(void* self, u32 a, u32 b, float x, float y);
extern const float lbl_27_rodata_1070;

extern "C" void fn_27_13DEF0(void* self, u32 a, u32 b) {
    float x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x60), 0xBE6, 0);
    fn_27_8CE54(self, a, b, x, lbl_27_rodata_1070 * x);
}
