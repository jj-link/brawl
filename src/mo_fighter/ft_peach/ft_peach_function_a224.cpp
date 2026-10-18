#include <types.h>
#pragma force_active on

struct PeachCountHolder {
    u32 pad[3];
    s32* counts;
};

extern "C" void fn_103_A224(PeachCountHolder* self, s32 index) {
    self->counts[index] -= 1;
}
