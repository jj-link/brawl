#include <so/so_module_accesser.h>
#pragma force_active on

// Float accesser: a header records the first index served by an inline,
// variable-length table of float arrays. The lookup subtracts that base
// from the requested index, then indexes the table by element.
struct Fn95FloatAccesser {
    u8 prefix[0x10];
    u32 indexBase;         // 0x10: first index served by the pointer table
    u8 gap[0x4];           // 0x14: header field not accessed by this lookup
    float* floatArrays[1]; // 0x18: inline, variable-length table of float arrays
};

extern "C" {

float fn_95_1D88C(Fn95FloatAccesser* self, soModuleAccesser* accesser, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
}
