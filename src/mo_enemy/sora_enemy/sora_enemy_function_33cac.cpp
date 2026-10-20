#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_41_rodata_E30;

void fn_41_33CAC(void* p) {
    float x = lbl_41_rodata_E30;
    *(float*)((char*)p + 12) = x;
    *(float*)((char*)p + 8) = x;
}
}
