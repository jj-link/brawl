#include <types.h>
#pragma force_active on

extern "C" void fn_27_26399C(void*);
extern "C" const float lbl_70_rodata_E8;

extern "C" void fn_70_7E38(void* self, int unused, const float* p) {
    float f31 = p[1];
    u8* s = reinterpret_cast<u8*>(self);
    fn_27_26399C(*reinterpret_cast<void**>(s + 0x14c));
    float v = *reinterpret_cast<float*>(s + 0x1dc);
    v = v - f31;
    *reinterpret_cast<float*>(s + 0x1dc) = v;
    if (v < lbl_70_rodata_E8) {
        *reinterpret_cast<float*>(s + 0x1dc) = lbl_70_rodata_E8;
    }
}
