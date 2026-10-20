#include <types.h>
#pragma force_active on

struct FnSelf {
    char pad[8];
    s32 f8;
};

extern "C" {
void* fn_27_D8F80(FnSelf* self, s32 idx) {
    s32 n = (self->f8 >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (char*)self + n * 4 + 0xC;
}
}
