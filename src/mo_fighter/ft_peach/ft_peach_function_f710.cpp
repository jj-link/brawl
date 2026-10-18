#include <types.h>
#pragma force_active on

struct PeachFlags {
    u32 pad : 6;
    u32 field : 6;
    u32 rest : 20;
};

#define FIELD(self) (reinterpret_cast<PeachFlags *>(self) + 2)

extern "C" void fn_103_F710(u32 *self, u32 arg1)
{
    FIELD(self)->field = arg1;
}
