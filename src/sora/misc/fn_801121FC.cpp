#include <types.h>
#pragma force_active on

extern "C" void fn_801121FC(void* a, unsigned short b, const float* c) {
    int base = *(int*)((char*)a + 0x10);
    float* p = (float*)(base + b * 16);
    p[0] = c[0];
    p[1] = c[1];
}
