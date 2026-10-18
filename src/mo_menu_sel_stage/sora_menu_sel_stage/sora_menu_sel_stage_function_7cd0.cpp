#include <types.h>
#pragma force_active on

extern "C" u32 fn_11_7CD0(u8* table, u32 index, u32) {
    return *reinterpret_cast<u32*>(table + index * 0x10 + 0x4C);
}
