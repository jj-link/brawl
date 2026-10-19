#include <types.h>
#pragma force_active on

struct Fn123Work {
    u8 _pad[0xc];
    void** m_table;
};

extern "C" {
void* fn_123_A580(Fn123Work* self, u32 index)
{
    return self->m_table[index];
}
}
