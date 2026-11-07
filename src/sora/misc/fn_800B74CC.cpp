#include <sr/sr_common.h>
#pragma force_active on
extern "C" void* fn_800B2474(void*, int, int, int, int, int, int);
extern "C" void* fn_800B74CC(int a, int b, int c, int d, Heaps::HeapType heap) {
    void* p = operator new(0x60, heap);
    if (p != 0) {
        p = fn_800B2474(p, a, b, c, d, 0, heap);
    }
    return p;
}