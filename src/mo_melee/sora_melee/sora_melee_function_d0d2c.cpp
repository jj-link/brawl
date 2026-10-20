#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_D0D2C(void *obj) {
    u32 v = *(u32 *)((char *)obj + 8);
    return (v >> 10) & 1;
}
