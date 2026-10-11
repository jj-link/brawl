#include <types.h>

struct PeachVector2 {
    f32 x;
    f32 y;
};

struct PeachVectorOwner {
    u8 unknown[8];
    PeachVector2 vector;
};

extern "C" {
extern const f32 lbl_103_rodata_8;
PeachVector2* fn_103_C174(PeachVector2* destination, const PeachVector2* source);

void fn_103_C13C(PeachVectorOwner* state) {
    PeachVector2 zero = { lbl_103_rodata_8, lbl_103_rodata_8 };
    fn_103_C174(&state->vector, &zero);
}
}
