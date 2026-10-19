#include <stddef.h>
#pragma force_active on

extern "C" void *fn_104_BFE8(char *base, int kind)
{
    if (kind == 2) return base + 0x3e4c;
    if (kind == 1) return base + 0x1f30;
    if (kind == 0) return base + 0x14;
    return NULL;
}
