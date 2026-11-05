#include <so/so_array.h>
#pragma force_active on

struct FalcoArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct FalcoArrayAggregate {
    void* vtable;
    FalcoArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" FalcoArrayTriple fn_108_B430(FalcoArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        FalcoArrayTriple result = { 0, 0, 0 };
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
    FalcoArrayTriple result = { c, a, b };
    return result;
}
