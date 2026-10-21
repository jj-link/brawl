#include <types.h>
#pragma force_active on

extern "C" void fn_80297720(f32* out, const f32* in, f32 scalar) {
    out[0] = scalar * in[0];
    out[1] = scalar * in[1];
    out[2] = scalar * in[2];
    out[3] = scalar * in[3];
}
