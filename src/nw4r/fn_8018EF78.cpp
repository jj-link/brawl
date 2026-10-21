#include <types.h>
#pragma force_active on

extern "C" void* fn_8018EF78(void* arg) {
    void* p = *(void**)arg;
    s32 offset = *(s32*)((char*)p + 0x18);
    if (offset != 0) {
        p = (void*)((char*)p + offset);
    } else {
        p = 0;
    }
    if (p != 0) {
        return *(void**)((char*)p + 4);
    }
    return 0;
}
