#include <string.h>
#pragma force_active on

extern "C" char* fn_14_F58(char* base, const char* src, int idx) {
    return strcpy(base + idx * 0x51 + 0x2325, src);
}
