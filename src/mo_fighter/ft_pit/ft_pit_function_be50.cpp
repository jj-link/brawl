#include <stddef.h>
#pragma force_active on

extern "C" void* fn_112_BE50(char* pool, int index) {
    if (index == 3) return pool + 0x5fac;
    if (index == 2) return pool + 0x3fd0;
    if (index == 1) return pool + 0x1ff4;
    if (index == 0) return pool + 0x18;
    return NULL;
}
