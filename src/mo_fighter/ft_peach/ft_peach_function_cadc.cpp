#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_CADC(u8* array, s32 index) {
    if (index == 0) {
        return array + 0xC;
    }
    return 0;
}
}
