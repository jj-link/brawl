#include <types.h>

#pragma force_active on

extern "C" u32 fn_114_C6AC(const void* object) {
    return *reinterpret_cast<const u32*>(static_cast<const char*>(object) + 0x28);
}

extern "C" u32 fn_114_C6B4(const void*) {
    return 0;
}
