#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_119_rodata_1C;
void fn_119_8F00(f32 *vector, f32 x, f32 y, f32 z);

void fn_119_B790(f32 *vector) {
    fn_119_8F00(vector, lbl_119_rodata_1C, lbl_119_rodata_1C, lbl_119_rodata_1C);
}
}
