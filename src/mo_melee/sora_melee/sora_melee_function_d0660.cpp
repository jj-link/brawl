#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_D0660(const void *p)
{
    return *(s32 *)((const char *)p + 0x8) >> 25;
}
}
