#include <types.h>
#pragma force_active on
extern "C" int fn_80079484(void* a, u32 b) {
    char* d = (char*)a;
    int c;
    for (c = 0; c < 24; ++c) {
        int index = *(int*)(d + 0x1fc);
        char* e = *(char**)((char*)a + 0x194);
        if (*(u32*)(e + index * 0x30 + 4) >= b) break;
        d += 0xc8;
    }
    return c;
}