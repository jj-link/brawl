#include <types.h>
#pragma force_active on

extern const float lbl_805A3B84;

void fn_8027A82C(void* p) {
    float x = lbl_805A3B84;
    *(float*)((char*)p + 8) = x;
    *(float*)((char*)p + 12) = x;
}
