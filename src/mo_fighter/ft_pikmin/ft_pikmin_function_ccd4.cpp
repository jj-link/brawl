#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad[0x14];
    float* data;
} Fn113Work;

extern "C" void fn_113_CCD4(Fn113Work* work, u32 index, float value) {
    work->data[index] -= value;
}
