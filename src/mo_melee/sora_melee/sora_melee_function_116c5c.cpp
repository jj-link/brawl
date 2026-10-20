#include <types.h>
#pragma force_active on

extern "C" void fn_27_13C1F0(float value, void* obj);

extern "C" void fn_27_116C5C(float f, void* p) {
    u8* self = (u8*)p;
    if (self[0xf] == 6) {
        u32 idx = self[0xa];
        fn_27_13C1F0(-f, *(void**)(self + (idx << 3) + 0x34));
        if (self[0xe] & 2) {
            fn_27_13C1F0(-f, *(void**)(self + 0x3c));
        }
    }
}
