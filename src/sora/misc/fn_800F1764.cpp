#include <memory.h>
#pragma force_active on

extern "C" void fn_800F1764(char* self)
{
    memset(self + 0x14, 0, 0x14);
}
