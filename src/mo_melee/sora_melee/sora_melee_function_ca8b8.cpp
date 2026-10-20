#include <types.h>
#pragma force_active on

struct X {
    u32 pad0;
    u32 pad4;
    u32 field;
};

extern "C" s32 fn_27_CA8B8(const X *self) {
    return (self->field >> 16) & 1;
}
