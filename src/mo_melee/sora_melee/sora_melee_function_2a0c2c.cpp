#include <types.h>
#pragma force_active on

extern "C" {
void* fn_800A6A94(void* base, s16 deleteFlag);
void __dl__FPv(void* ptr);

void* fn_27_2A0C2C(void* self, s16 deleteFlag) {
    if (self) {
        fn_800A6A94(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
