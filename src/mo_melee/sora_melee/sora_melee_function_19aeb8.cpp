#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_19AEB8(void* obj) {
    u32 v = *reinterpret_cast<u32*>(static_cast<u8*>(obj) + 8);
    return (v >> 16) & 1;
}
