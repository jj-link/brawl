#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct KirbyArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct KirbyArrayAggregate {
    void* vtable;
    KirbyArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" s32 fn_96_F5E8(KirbyArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
