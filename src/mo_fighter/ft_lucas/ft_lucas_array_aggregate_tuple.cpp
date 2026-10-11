#include <so/so_array.h>
#include <types.h>

struct LucasArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct LucasArrayTupleAggregate {
    void* vtable;
    LucasArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" {
LucasArrayTriple fn_114_D068(LucasArrayTupleAggregate* arrays, s32 index);

LucasArrayTriple* fn_114_D014(LucasArrayTupleAggregate* arrays, s32 index) {
    arrays->cache = fn_114_D068(arrays, index);
    return &arrays->cache;
}

LucasArrayTriple fn_114_D068(LucasArrayTupleAggregate* arrays, s32 index) {
    if (index < 0) {
        LucasArrayTriple result = { 0, 0, 0 };
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
    LucasArrayTriple result = { c, a, b };
    return result;
}

// The original const accessor returns a reference to its temporary tuple.
// Preserve that lifetime behavior rather than redirecting it to the cache.
const LucasArrayTriple& fn_114_D194(LucasArrayTupleAggregate* arrays, s32 index) {
    return fn_114_D068(arrays, index);
}
}
