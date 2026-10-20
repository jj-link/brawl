#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2FAEB4(char* p, int unused, int a, int b) {
    int off = (a - *(int*)(p + 0x14)) << 2;
    void** arr = *(void***)(p + off + 0x2c);
    return arr[b];
}
