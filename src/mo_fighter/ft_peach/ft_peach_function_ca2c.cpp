#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_CA2C(void* array, s32 index) {
    if (index == 0) {
        return (u8*)array + 0xC;
    }
    return 0;
}
}
