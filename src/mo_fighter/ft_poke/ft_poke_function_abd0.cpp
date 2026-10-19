#include <types.h>
#pragma force_active on

struct PokeArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct PokeArrayAggregate;

extern "C" PokeArrayTriple fn_116_AAA4(PokeArrayAggregate* arrays, s32 index);

extern "C" const PokeArrayTriple& fn_116_ABD0(PokeArrayAggregate* arrays, s32 index) {
    return fn_116_AAA4(arrays, index);
}
