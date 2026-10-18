#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_112_rodata_8;
void fn_112_9F54(void *self, f32 x, f32 y, f32 z);

void fn_112_CD00(void *self) {
    fn_112_9F54(self, lbl_112_rodata_8, lbl_112_rodata_8, lbl_112_rodata_8);
}
}
