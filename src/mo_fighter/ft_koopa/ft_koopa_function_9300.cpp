#include <types.h>
#pragma force_active on

extern "C" u32 fn_102_9300(u32* table, u32 index) {
    u32* kinds = *reinterpret_cast<u32**>(reinterpret_cast<char*>(table) + 0xc);
    return kinds[index];
}
