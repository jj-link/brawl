#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D9340(void* self, s32 idx) {
    char* base = (char*)self;
    s32 v = *(s32*)(base + 8);
    s32 n = (v >> 25) + idx;
    if (n >= 0x25) {
        n -= 0x25;
    }
    return base + n * 0x30 + 0xc;
}
