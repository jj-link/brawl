#include <types.h>
#pragma force_active on

struct Fn109Work {
    u8 pad[0xc];
    s32* values;
};

extern "C" void fn_109_934C(Fn109Work* work, s32 value, u32 index) {
    work->values[index] += value;
}
