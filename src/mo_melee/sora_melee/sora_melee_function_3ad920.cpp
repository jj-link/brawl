#include <types.h>
#pragma force_active on

extern "C" void fn_27_3AD97C(void*, s32);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3AD920(void* self, s32 flag) {
    if (self) {
        fn_27_3AD97C((u8*)self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
