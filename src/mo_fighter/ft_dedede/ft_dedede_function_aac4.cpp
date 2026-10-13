#include <types.h>

struct DededeArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct DededeArrayAggregate;

extern "C" DededeArrayTriple fn_117_A998(DededeArrayAggregate* arrays, s32 index);

extern "C" const DededeArrayTriple& fn_117_AAC4(DededeArrayAggregate* arrays, s32 index) {
    // Preserve the original const accessor's reference to its temporary result.
    return fn_117_A998(arrays, index);
}
