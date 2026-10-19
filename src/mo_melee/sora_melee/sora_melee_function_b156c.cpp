#include <types.h>
#pragma force_active on

struct fn_27_B156C_entry {
    f32 unk0;
    s32 unk4;
    f32 unk8;
};

extern "C" {
extern const f32 lbl_27_rodata_DA8;
void fn_27_B156C(fn_27_B156C_entry* base, s32 idx, s32 value, f32 a, f32 b) {
    base[idx].unk4 = value;
    if (a >= lbl_27_rodata_DA8) {
        base[idx].unk8 = a;
    }
    if (b >= lbl_27_rodata_DA8) {
        base[idx + 1].unk0 = b;
    }
}
}
