#include <so/so_array.h>
#include <types.h>

struct MarthArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct MarthArrayAggregate {
    void* vtable;
    MarthArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" {
MarthArrayTriple fn_106_84E0(MarthArrayAggregate* arrays, s32 index);

s32 fn_106_83D8(const MarthArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}

MarthArrayTriple* fn_106_848C(MarthArrayAggregate* arrays, s32 index) {
    arrays->cache = fn_106_84E0(arrays, index);
    return &arrays->cache;
}

MarthArrayTriple fn_106_84E0(MarthArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        MarthArrayTriple result = { 0, 0, 0 };
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
    MarthArrayTriple result = { c, a, b };
    return result;
}

// The original const accessor returns a reference to its temporary tuple.
// Preserve that lifetime behavior rather than redirecting it to the cache.
const MarthArrayTriple& fn_106_860C(MarthArrayAggregate* arrays, s32 index) {
    return fn_106_84E0(arrays, index);
}
}
