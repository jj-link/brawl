#include <types.h>
#pragma force_active on

struct DiddyTriple {
    u32 a;
    u32 b;
    u32 c;
};

struct DiddyAggregate {
    void* vtable;
    DiddyTriple cache;
};

extern "C" DiddyTriple fn_115_A5B4(DiddyAggregate* self, s32 index);

extern "C" DiddyTriple* fn_115_A560(DiddyAggregate* self, s32 index) {
    self->cache = fn_115_A5B4(self, index);
    return &self->cache;
}
