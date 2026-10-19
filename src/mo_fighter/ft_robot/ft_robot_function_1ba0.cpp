#include <types.h>
#pragma force_active on

extern "C" void fn_120_1B3C(void* self, s16 arg);

extern "C" void* fn_120_1BA0(void* self, s16 flags) {
    if (self != 0) {
        s16 zero = 0;
        fn_120_1B3C(self, zero);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
