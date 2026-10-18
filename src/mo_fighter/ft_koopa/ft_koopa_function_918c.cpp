#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

typedef struct FtKoopaTable
{
    char pad[0x1c];
    u32 *m_table;
} FtKoopaTable;

extern "C" void fn_102_918C(FtKoopaTable *self, u32 index)
{
    self->m_table[index] = 0;
}
