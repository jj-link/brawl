#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_122_rodata_C;
void fn_122_D580(void* p, f32 x, f32 y, f32 z);

void fn_122_12D88(void* p) {
    fn_122_D580(p, lbl_122_rodata_C, lbl_122_rodata_C, lbl_122_rodata_C);
}
}
