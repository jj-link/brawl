#include <so/so_array.h>
#pragma force_active on

struct SonicArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct SonicArrayAggregate {
    void* vtable;
    SonicArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" SonicArrayTriple fn_123_A6A0(SonicArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        SonicArrayTriple zero = { 0, 0, 0 };
        return zero;
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
    SonicArrayTriple result = { c, a, b };
    return result;
}