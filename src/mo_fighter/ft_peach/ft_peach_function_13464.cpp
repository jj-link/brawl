#include <types.h>
#pragma force_active on

struct PeachVector2 {
    f32 x;
    f32 y;
};

extern "C" {
extern const f32 lbl_103_rodata_44;

PeachVector2 fn_103_13464(void) {
    PeachVector2 v = { lbl_103_rodata_44, lbl_103_rodata_44 };
    return v;
}
}
