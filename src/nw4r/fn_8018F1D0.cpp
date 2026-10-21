#include <types.h>
#pragma force_active on

extern "C" void* fn_8018F1D0(void* arg) {
    void* p = *(void**)arg;
    s32 offset = *(s32*)((char*)p + 0x20);
    if (offset != 0) {
        p = (char*)p + offset;
    } else {
        p = NULL;
    }
    if (p != NULL) {
        return *(void**)((char*)p + 4);
    }
    return 0;
}
