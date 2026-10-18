#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_113_rodata_C;
void fn_113_A1D0(void* p, f32 x, f32 y, f32 z);

void fn_113_EFE8(void* p) {
    fn_113_A1D0(p, lbl_113_rodata_C, lbl_113_rodata_C, lbl_113_rodata_C);
}
}
