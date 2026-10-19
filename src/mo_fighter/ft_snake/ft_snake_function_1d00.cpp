#include <types.h>
#pragma force_active on

extern "C" {
void fn_122_1AD0(void* self, s16 arg);
void* fn_122_1D00(void* self, s16 flags);
}

void* fn_122_1D00(void* self, s16 flags) {
    if (self != nullptr) {
        fn_122_1AD0(self, 0);
        if (flags > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
