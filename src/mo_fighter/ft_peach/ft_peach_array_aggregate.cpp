#include <so/so_array.h>
#include <types.h>

struct PeachArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct PeachArrayAggregate {
    void* vtable;
    PeachArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" {
PeachArrayTriple fn_103_A3EC(PeachArrayAggregate* arrays, s32 index);

s32 fn_103_A2E4(const PeachArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}

PeachArrayTriple* fn_103_A398(PeachArrayAggregate* arrays, s32 index) {
    arrays->cache = fn_103_A3EC(arrays, index);
    return &arrays->cache;
}

PeachArrayTriple fn_103_A3EC(PeachArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        PeachArrayTriple result = { 0, 0, 0 };
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
    PeachArrayTriple result = { c, a, b };
    return result;
}

// The original const accessor returns a reference to its temporary tuple.
// Preserve that lifetime behavior rather than redirecting it to the cache.
const PeachArrayTriple& fn_103_A518(PeachArrayAggregate* arrays, s32 index) {
    return fn_103_A3EC(arrays, index);
}
}
