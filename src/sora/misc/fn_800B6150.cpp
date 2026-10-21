#include <types.h>
#pragma force_active on

extern "C" void* fn_800B6150(void* self) {
    void* b = *(void**)((char*)self + 0x14);
    void* c = *(void**)((char*)b + 0x14);
    if (!c) return 0;
    void* d = *(void**)((char*)c + 0x2c);
    s32 offset = *(s32*)((char*)d + 0x14);
    if (offset != 0) return (void*)((char*)d + offset);
    return 0;
}
