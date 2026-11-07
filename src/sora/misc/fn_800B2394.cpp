#include <mu/mu_object.h>
#include <sr/sr_common.h>
#pragma force_active on
extern "C" MuObject* fn_800B2474(void*, nw4r::g3d::ResFile*, const char*, int, nw4r::g3d::ResFile*, int, Heaps::HeapType);
MuObject* MuObject::create(nw4r::g3d::ResFile* a, const char* b, int c, nw4r::g3d::ResFile* d, Heaps::HeapType heap) {
    void* p = operator new(0x60, heap);
    if (p != 0) {
        p = fn_800B2474(p, a, b, c, d, 1, heap);
    }
    return (MuObject*)p;
}