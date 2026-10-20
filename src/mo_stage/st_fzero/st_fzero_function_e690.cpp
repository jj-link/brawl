#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

struct FzeroWork {
    char pad[0x5b0];
    float* m_floatTable;
};

extern "C" float fn_61_E690(const FzeroWork* self, u32 index) {
    return self->m_floatTable[index];
}
