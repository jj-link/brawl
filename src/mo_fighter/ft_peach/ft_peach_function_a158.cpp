#include <types.h>
#pragma force_active on

struct PeachIndexedOwner {
    u8 pad[0x1c];
    u32* values;
};

extern "C" void fn_103_A158(PeachIndexedOwner* owner, s32 index) {
    owner->values[index] = 0;
}
