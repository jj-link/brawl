#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D91D8(void* self, s32 idx) {
    char* base = (char*)self;
    s32 n = (*(s32*)(base + 8) >> 24) + idx;
    if (n >= 0x41) {
        n -= 0x41;
    }
    return base + n * 0x30 + 0xc;
}
