#include <types.h>
#pragma force_active on

struct PeachSubArray {
    void* vtable;
    u32 pad[2];
    u32* values;
};

extern "C" void fn_103_A28C(PeachSubArray* self, u32 amount, s32 index) {
    self->values[index] -= amount;
}
