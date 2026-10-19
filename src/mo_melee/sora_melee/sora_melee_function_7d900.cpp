#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* array);

extern "C" void* fn_27_7D900(void* array, s32 count) {
    if (array != nullptr && count > 0) {
        __dl__FPv(array);
    }
    return array;
}
