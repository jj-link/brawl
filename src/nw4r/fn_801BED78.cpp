#include <types.h>
#pragma force_active on

extern "C" void fn_801C6B94(void* self);
extern "C" int fn_801F6524(void* self);

extern "C" void fn_801BED78(u8* self) {
    fn_801F6524(self + 0x14c);
    self[0x188] = 0;
    fn_801C6B94(self);
}
