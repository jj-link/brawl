#include <types.h>
#pragma force_active on

extern "C" void fn_801B8CB0(void* self, u32 x);

extern "C" void fn_801D18DC(u8* self, u32 x) {
    u8* outer = self;
    u8* p;
    s32 i = 0;
    s32 j;
    for (; i < *(s32*)(self + 0x9C); i++) {
        p = outer;
        for (j = 0; j < *(s32*)(self + 0xA0); j++) {
            void* v = *(void**)(p + 0xC);
            if (v != 0) {
                fn_801B8CB0(v, x);
            }
            p += 4;
        }
        outer += 0x10;
    }
}
