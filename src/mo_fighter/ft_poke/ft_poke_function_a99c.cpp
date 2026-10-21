#include <so/so_array.h>
#pragma force_active on

struct PokeArrayAggregate {
    void* vtable;
    u32 cache[3];
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" s32 fn_116_A99C(PokeArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
