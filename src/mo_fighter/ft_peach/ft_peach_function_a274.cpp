#include <types.h>
#pragma force_active on

struct PeachScaleOwner {
    void* vtable;
    u32 pad4;
    u32 pad8;
    u32* values;
};

extern "C" void fn_103_A274(PeachScaleOwner* owner, u32 scale, s32 index) {
    owner->values[index] *= scale;
}
