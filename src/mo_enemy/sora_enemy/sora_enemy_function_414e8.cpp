#include <stddef.h>
#pragma force_active on

extern "C" void* fn_41_414E8(char* p, int k) {
    if (k == 5) return p + 0xfc;
    if (k == 4) return p + 0xd0;
    if (k == 3) return p + 0xa4;
    if (k == 2) return p + 0x78;
    if (k == 1) return p + 0x4c;
    if (k == 0) return p + 0x20;
    return NULL;
}
