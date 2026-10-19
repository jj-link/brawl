#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A4D90(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_17618(void* ptr, s16 count) {
    if (ptr != 0) {
        fn_27_1A4D90(ptr, -1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
