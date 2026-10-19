#include <types.h>
#pragma force_active on

extern "C" {
void* fn_800A6A94(void* base, s16 deleteFlag);

void* fn_122_AA80(void* self, s16 deleteFlag) {
    if (self != 0) {
        fn_800A6A94(self, 0);
        if (deleteFlag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
