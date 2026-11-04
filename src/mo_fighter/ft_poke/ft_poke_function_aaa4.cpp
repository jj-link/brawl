#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct Triple { u32 c, a, b; };
struct Aggregate {
    void* vtable;
    Triple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" Triple fn_116_AAA4(Aggregate* arrays, s32 index) {
    if (index < 0) {
        Triple result = { 0, 0, 0 };
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
    Triple result = { c, a, b };
    return result;
}