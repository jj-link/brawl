#include <so/so_array.h>

struct DededeArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct DededeArrayAggregate {
    void* vtable;
    DededeArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" s32 fn_117_A890(DededeArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
