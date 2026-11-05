#include <types.h>
#pragma force_active on

extern "C" void fn_80164B1C(void*, u32);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_80164738(void* self, s32 flags) {
    if (self != 0) {
        for (u32 i = 0; i < *(u32*)((char*)self + 0x5014); ++i) {
            fn_80164B1C(self, i);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
