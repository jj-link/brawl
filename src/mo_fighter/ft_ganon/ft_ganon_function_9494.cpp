#include <so/so_array.h>
#pragma force_active on

struct GanonArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct GanonArrayAggregate {
    void* vtable;
    GanonArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" GanonArrayTriple fn_109_9494(GanonArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        GanonArrayTriple result = { 0, 0, 0 };
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
    GanonArrayTriple result = { c, a, b };
    return result;
}