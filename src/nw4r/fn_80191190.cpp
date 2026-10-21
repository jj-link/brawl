#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_80191190(void** p) {
    void* inner = *p;
    if (inner) {
        return *(s8*)((u8*)inner + 0x2);
    }
    return -1;
}
}
