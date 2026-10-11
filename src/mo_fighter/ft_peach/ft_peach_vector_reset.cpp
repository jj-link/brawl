#include <types.h>

struct PeachVector2 {
    f32 x;
    f32 y;
};

struct PeachVectorState {
    u8 unknown[8];
    PeachVector2 first;
    PeachVector2 second;
    PeachVector2 third;
    PeachVector2 fourth;
    PeachVector2 fifth;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" {
extern const f32 lbl_103_rodata_8;
extern const f32 lbl_103_rodata_C;
PeachVector2* fn_103_C174(PeachVector2* destination, const PeachVector2* source);

void fn_103_C188(PeachVectorState* state) {
    PeachVector2 zero = { lbl_103_rodata_8, lbl_103_rodata_8 };
    fn_103_C174(&state->first, fn_103_C174(&state->second, fn_103_C174(&state->fourth, &zero)));
    PeachVector2 negative = { lbl_103_rodata_C, lbl_103_rodata_C };
    fn_103_C174(&state->third, fn_103_C174(&state->fifth, &negative));
    state->flag31 = 0;
    state->flag30 = 0;
    state->flag32 = 1;
}
}
