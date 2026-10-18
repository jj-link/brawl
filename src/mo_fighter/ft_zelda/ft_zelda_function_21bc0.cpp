#include <types.h>
#pragma force_active on

struct FloatTableAccesser {
    u8 prefix[0x10];
    u32 indexBase;         // 0x10: first index served by the pointer table
    u8 gap[0x4];           // 0x14: header field not accessed by this lookup
    float* floatArrays[1]; // 0x18: inline, variable-length table of float arrays
};

extern "C" {

float fn_104_21BC0(FloatTableAccesser* self, void* unused, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
}
