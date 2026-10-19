#include <types.h>
#pragma force_active on

extern "C" const float lbl_114_rodata_C8;

extern "C" u64 fn_114_15D04() {
    float tmp[2];
    tmp[0] = lbl_114_rodata_C8;
    tmp[1] = lbl_114_rodata_C8;
    return *(u64*)tmp;
}
