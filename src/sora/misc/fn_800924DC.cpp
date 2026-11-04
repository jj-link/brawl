#pragma force_active on
#include <types.h>

extern "C" void fn_801EC158(void* p);
extern "C" void fn_801EC868(void* pIn, void* pOut, float x, float y, float z);

extern "C" void fn_800924DC(void* a, float* b, float* c) {
    u8 buf[0x30];
    fn_801EC158(buf);
    fn_801EC868(buf, (char*)a + 0x68, b[0], b[1], b[2]);
    fn_801EC868(buf, (char*)a + 0x98, c[0], c[1], c[2]);
}