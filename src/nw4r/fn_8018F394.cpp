#include <types.h>
#pragma force_active on

extern "C" u32 fn_8018F394(void* arg) {
    u8* base = *(u8**)arg;
    u32 offset = *(u32*)(base + 0x28);
    u8* p;
    if (offset != 0) {
        p = base + offset;
    } else {
        p = NULL;
    }
    if (p != NULL) {
        return *(u32*)(p + 4);
    }
    return 0;
}
