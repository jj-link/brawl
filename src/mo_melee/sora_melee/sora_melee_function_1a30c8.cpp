#include <types.h>
#pragma force_active on

extern "C" int fn_27_1A30C8(const void* a)
{
    int v = *(const int*)((const char*)a + 8);
    return (v >> 22) & 1;
}
