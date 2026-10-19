#include <so/so_array.h>
#pragma force_active on

struct PokeArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct PokeArrayAggregate {
    void* vtable;
    PokeArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" PokeArrayTriple fn_116_AAA4(PokeArrayAggregate* arrays, s32 index);

extern "C" PokeArrayTriple* fn_116_AA50(PokeArrayAggregate* arrays, s32 index) {
    arrays->cache = fn_116_AAA4(arrays, index);
    return &arrays->cache;
}
