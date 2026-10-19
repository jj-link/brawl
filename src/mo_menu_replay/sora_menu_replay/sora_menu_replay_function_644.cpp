#include <types.h>
#pragma force_active on

extern "C" void* fn_7_644(void* arg) {
    void* a = *(void**)((char*)arg + 0x1AC);
    void* b = *(void**)((char*)a + 0x1D0C);
    void* c = *(void**)((char*)b + 0x35C);
    void* d = *(void**)c;
    if (*(u8*)((char*)d + 0x1A4) != 0) {
        return *(void**)((char*)d + 0x48);
    }
    return 0;
}
