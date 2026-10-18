#include <ft/ft_common_data_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
float fn_27_145578(void* unused, u32 p1, u32 p2) {
    u8* p = (u8*)&g_ftCommonData - 0x30ac;
    return *(float*)(p + p1 * 0x5f8 + p2 * 4);
}
}
