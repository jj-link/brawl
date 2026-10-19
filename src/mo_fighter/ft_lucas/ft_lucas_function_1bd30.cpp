#include <types.h>
#pragma force_active on

extern "C" void* fn_27_6A3D8(void* self, short value);
extern "C" void* fn_27_199E3C(void* self, short value);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_114_1BD30(void* self, short freeFlag) {
    if (self != 0) {
        fn_27_6A3D8(static_cast<u8*>(self) + 0x144, -1);
        fn_27_199E3C(self, -1);
        if (freeFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
