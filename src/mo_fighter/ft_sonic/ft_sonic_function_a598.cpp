#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct SonicArrayAggregate {
    void* vtable;
    u32 cache[3];
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" s32 fn_123_A598(const SonicArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
