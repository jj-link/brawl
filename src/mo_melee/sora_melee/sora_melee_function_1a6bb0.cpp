#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_1A6BB0(const void* p) {
    u32 val = *reinterpret_cast<const u32*>(static_cast<const u8*>(p) + 8);
    return (val >> 1) & 1;
}
}
