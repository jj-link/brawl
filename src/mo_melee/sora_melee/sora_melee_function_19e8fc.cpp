#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_19E8FC(const void *p) {
    u32 val = *(const u32 *)((const char *)p + 8);
    return (val >> 16) & 1;
}
