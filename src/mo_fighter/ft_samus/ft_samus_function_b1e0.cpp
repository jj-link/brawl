#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct SamusArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct SamusArrayAggregate {
    void* vtable;
    SamusArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" SamusArrayTriple fn_94_B1E0(SamusArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        SamusArrayTriple result = { 0, 0, 0 };
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
    SamusArrayTriple result = { c, a, b };
    return result;
}
