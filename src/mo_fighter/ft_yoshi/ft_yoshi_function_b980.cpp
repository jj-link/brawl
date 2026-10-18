#include <types.h>
#pragma force_active on

struct FtYoshiWork {
    u8 pad[0xc];
    u32* m_values;
};

extern "C" void fn_95_B980(FtYoshiWork* self, u32 value, u32 index) {
    self->m_values[index] += value;
}
