#include <types.h>
#pragma force_active on

struct FebaBits {
    u32 pad[2];
    u32 hi : 2;
    u32 f : 2;
    u32 lo : 28;
};

extern "C" void fn_27_FEBA8(FebaBits* self, u32 v) {
    self->f = v;
}
