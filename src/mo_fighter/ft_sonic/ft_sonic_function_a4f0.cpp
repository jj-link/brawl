#include <types.h>
#pragma force_active on

struct FtSonicCounterOwner {
    u8 pad[0xc];
    s32 *counts;
};

extern "C" {
void fn_123_A4F0(FtSonicCounterOwner *owner, u32 index) {
    owner->counts[index]++;
}
}
