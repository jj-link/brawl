#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct IceTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct IceAgg {
    void* vtable;
    IceTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" IceTriple fn_105_DF5C(IceAgg* agg, s32 index) {
    if (index < 0) {
        IceTriple result = { 0, 0, 0 };
        return result;
    }
    u32 c = 0;
    if (index < agg->c->size()) c = agg->c->at(index);
    u32 a = 0;
    if (index < agg->a->size()) a = agg->a->at(index);
    u32 b = 0;
    if (index < agg->b->size()) b = agg->b->at(index);
    IceTriple result = { c, a, b };
    return result;
}