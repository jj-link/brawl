// Snake's article float accesser maps a range of consecutive value indices onto
// a table of float arrays stored inline behind the accesser header. The header
// records the first index the table serves (at +0x10); a lookup subtracts that
// base from the requested index before indexing the pointer table at +0x18, and
// then picks the element-th float out of the selected row.
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

struct SnakeArticleFloatAccesser {
    u8 prefix[0x10];
    u32 indexBase;         // +0x10: first index served by the pointer table
    u8 gap[0x4];           // +0x14: header field not accessed by this lookup
    float* floatArrays[1]; // +0x18: inline, variable-length table of float arrays
};

extern "C" {

float fn_122_20548(SnakeArticleFloatAccesser* self, soModuleAccesser* accesser, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
}
