#include <mu/mu_object.h>
#include <sr/sr_common.h>
#pragma force_active on
extern "C" void fn_800B2830(void*, nw4r::g3d::ResFile**, int, int, int, int, Heaps::HeapType);
extern "C" void create__8MuObjectFPPQ34nw4r3g3d7ResFileiciQ25Heaps8HeapType(nw4r::g3d::ResFile** a, int b, int c, int d, Heaps::HeapType heap) {
    void* p = operator new(0x60, heap);
    if (p != 0) {
        fn_800B2830(p, a, d, b, c, 1, heap);
    }
}
