#include <stddef.h>
#pragma force_active on

extern "C" void* fn_94_CE94(void* base, int index) {
    char* p = static_cast<char*>(base);
    if (index == 3) return p + 0x489c;
    if (index == 2) return p + 0x3070;
    if (index == 1) return p + 0x1844;
    if (index == 0) return p + 0x18;
    return NULL;
}
