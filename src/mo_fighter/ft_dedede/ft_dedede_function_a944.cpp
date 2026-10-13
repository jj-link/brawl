#include <so/so_array.h>

struct DededeArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct DededeArrayAggregate {
    void* vtable;
    DededeArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" DededeArrayTriple fn_117_A998(DededeArrayAggregate* arrays, s32 index);

extern "C" DededeArrayTriple* fn_117_A944(DededeArrayAggregate* arrays, s32 index) {
    arrays->cache = fn_117_A998(arrays, index);
    return &arrays->cache;
}
