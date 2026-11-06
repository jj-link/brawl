#include <so/so_array.h>
#pragma force_active on

struct LucarioArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct LucarioArrayAggregate {
    void* vtable;
    LucarioArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" LucarioArrayTriple fn_118_A688(LucarioArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        LucarioArrayTriple result = { 0, 0, 0 };
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
    LucarioArrayTriple result = { c, a, b };
    return result;
}