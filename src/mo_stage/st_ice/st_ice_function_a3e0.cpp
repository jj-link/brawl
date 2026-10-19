#include <types.h>
#pragma force_active on

extern "C" const float lbl_62_rodata_154;

struct St_A3E0 {
    u8 pad0[0x60];
    float f60;
    float f64;
    float f68;
    u8 pad6c[0x08];
    u32 flags74;
};

extern "C" void fn_62_A3E0(St_A3E0* object) {
    u32 flags = object->flags74;
    float zero = lbl_62_rodata_154;
    object->f60 = zero;
    object->f64 = zero;
    object->f68 = zero;
    object->flags74 = flags & ~0x1Fu;
}
