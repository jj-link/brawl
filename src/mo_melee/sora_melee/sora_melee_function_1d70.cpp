#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

// Best candidate so far: 97.6% match. The only remaining difference is an extra
// trailing blr after the tail call to setIdentity in the else branch (original
// ends with a bare `b`). Not resolved.
extern "C" {
void setIdentity__6MatrixFv(void*);

void fn_27_1D70(u8* self, f32* a, f32* b, nw4r::math::MTX34* m) {
    f32 b2;
    f32 b1;
    f32 b0;
    f32 a2;
    f32 a1;
    f32 a0;
    a0 = a[0];
    a1 = a[1];
    a2 = a[2];
    b0 = b[0];
    b1 = b[1];
    b2 = b[2];
    *(f32*)(self + 0x0) = a0;
    *(f32*)(self + 0x4) = a1;
    *(f32*)(self + 0x8) = a2;
    *(f32*)(self + 0x34) = b0;
    *(f32*)(self + 0x38) = b1;
    *(f32*)(self + 0x3C) = b2;
    if (m != NULL) {
        *(nw4r::math::MTX34*)(self + 0x40) = *m;
    } else {
        setIdentity__6MatrixFv(self + 0x40);
    }
}
}
