#include <types.h>

extern "C" void fn_10_1D45C(void*);
extern "C" void fn_10_1DE50(void*);

#pragma force_active on
extern "C" void fn_10_18DCC(void* self) {
    u8* base = reinterpret_cast<u8*>(self);
    fn_10_1D45C(base + 0x1fc);
    fn_10_1DE50(base + 0x1fc);
}
