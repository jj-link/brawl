#include <so/so_array.h>
#pragma force_active on

struct ToonlinkTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct ToonlinkAgg {
    void* vtable;
    ToonlinkTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" ToonlinkTriple fn_121_B4D0(ToonlinkAgg* agg, s32 index) {
    if (index < 0) {
        ToonlinkTriple zero = { 0, 0, 0 };
        return zero;
    }

    u32 c = 0;
    if (index < agg->c->size()) {
        c = agg->c->at(index);
    }

    u32 a = 0;
    if (index < agg->a->size()) {
        a = agg->a->at(index);
    }

    u32 b = 0;
    if (index < agg->b->size()) {
        b = agg->b->at(index);
    }

    ToonlinkTriple res = { c, a, b };
    return res;
}
