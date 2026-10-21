#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_80191170(void* p) {
    u8* inner = *(u8**)p;
    if (inner != 0) {
        return *(s8*)(inner + 1);
    }
    return -1;
}
}
