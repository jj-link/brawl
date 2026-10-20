#include <types.h>
#pragma force_active on

extern "C" void fn_27_12AE6C(void* self, u32 x);
extern "C" void fn_27_12AE90(void* self, u32 x);

extern "C" void fn_27_116CCC(u8* self, u32 a, u32 b) {
    void* p;
    u8* e = self;
    for (s32 i = 0; i < self[8]; ) {
        p = *(void**)(e + 0x34);
        if (p != 0) {
            fn_27_12AE6C(p, a);
            fn_27_12AE90(p, b);
        }
        e += 8;
        i++;
    }
}
