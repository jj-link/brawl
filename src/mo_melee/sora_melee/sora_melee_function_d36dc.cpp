#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D36DC(void* self, s32 flag) {
    if (self != nullptr && flag > 0) {
        operator delete(self);
    }
    return self;
}
