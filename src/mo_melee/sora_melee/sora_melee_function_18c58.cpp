#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_18C58(u8* self) {
    u32 b = (self[0x164] >> 2) & 1;
    return (-b | b) >> 31;
}
