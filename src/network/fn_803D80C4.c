#include <types.h>
#pragma force_active on

extern void fn_803D8E00(void* self, int mode);

void fn_803D80C4(u32* self) {
    *self |= 0x4;
    fn_803D8E00(self, 1);
}
