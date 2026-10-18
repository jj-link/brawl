#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_105_rodata_10;
void fn_105_C1C0(void* p, f32 x, f32 y, f32 z);

void fn_105_1048C(void* p) {
    fn_105_C1C0(p, lbl_105_rodata_10, lbl_105_rodata_10, lbl_105_rodata_10);
}
}
