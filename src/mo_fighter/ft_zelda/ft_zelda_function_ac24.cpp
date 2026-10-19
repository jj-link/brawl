#pragma force_active on
typedef unsigned int u32;

struct ZeldaArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct ZeldaArrayAggregate {
    void* vtable;
    ZeldaArrayTriple cache;
};

extern "C" ZeldaArrayTriple fn_104_AC78(ZeldaArrayAggregate* arrays, int index);

extern "C" ZeldaArrayTriple* fn_104_AC24(ZeldaArrayAggregate* arrays, int index) {
    arrays->cache = fn_104_AC78(arrays, index);
    return &arrays->cache;
}
