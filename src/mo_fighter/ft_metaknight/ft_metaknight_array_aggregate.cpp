#include <so/so_array.h>
#include <types.h>

struct MetaKnightArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct MetaKnightArrayAggregate {
    void* vtable;
    MetaKnightArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" {
MetaKnightArrayTriple fn_111_8B10(MetaKnightArrayAggregate* arrays, s32 index);

s32 fn_111_8A08(const MetaKnightArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}

MetaKnightArrayTriple* fn_111_8ABC(MetaKnightArrayAggregate* arrays, s32 index) {
    arrays->cache = fn_111_8B10(arrays, index);
    return &arrays->cache;
}

MetaKnightArrayTriple fn_111_8B10(MetaKnightArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        MetaKnightArrayTriple result = { 0, 0, 0 };
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
    MetaKnightArrayTriple result = { c, a, b };
    return result;
}

// The original const accessor returns a reference to its temporary tuple.
// Preserve that lifetime behavior rather than redirecting it to the cache.
const MetaKnightArrayTriple& fn_111_8C3C(MetaKnightArrayAggregate* arrays, s32 index) {
    return fn_111_8B10(arrays, index);
}
}
