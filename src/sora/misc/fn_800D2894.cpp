#include <string.h>
#pragma force_active on

extern "C" {
void fn_800D2894(char* base, int idx) {
    memset(base + idx * 0x218 + 0x1a8, 0, 0xa0);
}
}
