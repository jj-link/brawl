#include <types.h>
#pragma force_active on

struct PeachAddTarget {
    u32 pad[3];
    u32* data;
};

extern "C" {
void fn_103_A2A4(PeachAddTarget* target, u32 value, s32 index) {
    target->data[index] += value;
}
}
