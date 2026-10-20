#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

struct FnTable48 {
    char pad[0x44];
    u32 *table;
};

extern "C" u32 fn_48_7CB8(const FnTable48 *self, u32 index)
{
    return self->table[index];
}
