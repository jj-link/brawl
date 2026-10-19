#include <types.h>
#pragma force_active on

extern "C" s32 fn_104_AE30();

extern "C" float fn_104_ADD8(void* tables, void*, s32 parameter, s32 element) {
    s32 table = fn_104_AE30();
    const float* values =
        *(const float**)((u8*)tables + (table << 7) - 0x3E70 + (parameter << 2));
    return values[element];
}
