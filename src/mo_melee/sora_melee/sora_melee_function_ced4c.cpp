#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_CED4C(void* param) {
    u32 val = *(u32*)((u8*)param + 8);
    return (val >> 13) & 1;
}
