#include <so/so_array.h>
#pragma force_active on

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

static inline DededeArrayTriple fn_27_1E2038_get(DededeArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        DededeArrayTriple result = { 0, 0, 0 };
        return result;
    }
    u32 c = 0;
    if (index < arrays->c->size()) {
        c = arrays->c->at(index);
    }
    u32 a = 0;
    if (index < arrays->a->size()) {
        a = arrays->a->at(index);
    }
    u32 b = 0;
    if (index < arrays->b->size()) {
        b = arrays->b->at(index);
    }
    DededeArrayTriple result = { c, a, b };
    return result;
}

extern "C" DededeArrayTriple* fn_27_1E2038(DededeArrayAggregate* arrays, s32 index) {
    arrays->cache = fn_27_1E2038_get(arrays, index);
    return &arrays->cache;
}
