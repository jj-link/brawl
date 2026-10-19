#include <types.h>
#pragma force_active on

extern "C" const float lbl_67_rodata_14;

struct St {
    u8 pad[0x60];
    float f60;
    float f64;
    float f68;
    u8 pad2[8];
    u32 f74;
};

extern "C" void fn_67_4EBC(St* s) {
    u32 v = s->f74;
    float z = lbl_67_rodata_14;
    s->f60 = z;
    s->f64 = z;
    s->f68 = z;
    s->f74 = v & ~0x1Fu;
}
