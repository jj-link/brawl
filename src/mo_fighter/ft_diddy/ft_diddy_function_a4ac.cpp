#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct DiddyArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct DiddyArrayAggregate {
    void* vtable;
    DiddyArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" s32 fn_115_A4AC(DiddyArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
