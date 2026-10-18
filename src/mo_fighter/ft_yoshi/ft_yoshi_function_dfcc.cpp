#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_95_rodata_C;
void fn_95_ABB4(void* a, f32 x, f32 y, f32 z);

void fn_95_DFCC(void* a) {
    fn_95_ABB4(a, lbl_95_rodata_C, lbl_95_rodata_C, lbl_95_rodata_C);
}
}
