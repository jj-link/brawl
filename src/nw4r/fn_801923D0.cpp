#include <types.h>
#pragma force_active on

extern "C" void* fn_801923D0(void* ptr) {
    void* obj = *(void**)ptr;
    int offset = *(int*)((char*)obj + 0x34);
    if (offset)
        return (char*)obj + offset;
    return NULL;
}
