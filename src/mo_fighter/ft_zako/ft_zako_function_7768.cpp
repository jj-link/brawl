#include <types.h>
#pragma force_active on

struct ZakoArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct ZakoArrayAggregate {
    void* vtable;
    ZakoArrayTriple cache;
};

extern "C" ZakoArrayTriple fn_126_77BC(ZakoArrayAggregate* arrays, s32 index);

extern "C" ZakoArrayTriple* fn_126_7768(ZakoArrayAggregate* arrays, s32 index) {
    arrays->cache = fn_126_77BC(arrays, index);
    return &arrays->cache;
}
