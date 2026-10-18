#include <types.h>
#pragma force_active on

struct PeachCounterOwner {
    u8 pad[0xc];
    u32* counts;
};

extern "C" void fn_103_A23C(PeachCounterOwner* owner, s32 index) {
    owner->counts[index]++;
}
