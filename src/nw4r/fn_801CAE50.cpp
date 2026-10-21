#include <types.h>
#pragma force_active on

extern "C" float fn_801CAE50(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x38);
}
