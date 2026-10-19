#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A6A00(void* ptr, s16 count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_110_2960(void* self, s16 flag) {
    if (self != 0) {
        fn_27_1A6A00(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
