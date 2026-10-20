#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_385B54(void *param) {
    u32 val = *(u32 *)((char *)param + 8);
    return (val >> 1) & 1;
}
