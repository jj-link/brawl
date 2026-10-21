#include <so/so_array.h>
#pragma force_active on

struct SamusArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct SamusArrayAggregate {
    void* vtable;
    SamusArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" s32 fn_94_B0D8(SamusArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
