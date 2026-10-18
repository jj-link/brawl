#include <types.h>
#pragma force_active on

extern "C" const float lbl_114_rodata_C0;

struct LucasPairState {
    u32 header[2];
    float x;
    float y;
};

extern "C" void fn_114_159B0(LucasPairState* object) {
    object->y = lbl_114_rodata_C0;
    object->x = lbl_114_rodata_C0;
}
