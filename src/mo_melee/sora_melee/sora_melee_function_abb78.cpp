#include <types.h>
#pragma force_active on

extern "C" void fn_27_7756C(void* self);

extern "C" void* fn_27_ABB78(void* self, int unused, u32 a, const s16* b, s16 c) {
    fn_27_7756C(self);
    u8* p = (u8*)self;
    *(u32*)(p + 0x8) = a;
    *(s16*)(p + 0xc) = *b;
    *(s16*)(p + 0xe) = c;
    return self;
}
