#include <types.h>

#pragma force_active on

extern "C" u32 fn_27_19A668(const void* ptr)
{
    u32 val = *(const u32*)((const char*)ptr + 8);
    return (val >> 22) & 1;
}
