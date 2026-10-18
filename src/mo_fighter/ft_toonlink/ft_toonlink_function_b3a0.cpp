#include <types.h>
#pragma force_active on

struct Work121 {
    u32 pad[3];
    u32* data;
};

extern "C" void fn_121_B3A0(Work121* work, u32 value, u32 index) {
    work->data[index] = value;
}
