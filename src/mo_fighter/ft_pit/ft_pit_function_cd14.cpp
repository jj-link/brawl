#include <types.h>
#pragma force_active on

struct PitThing {
    u32 f0;
    u32 f4;
    u64 value;
};

extern "C" u64 fn_112_CD14(const PitThing* self) {
    return self->value;
}
