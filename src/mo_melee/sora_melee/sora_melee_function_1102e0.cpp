#include <types.h>
#pragma force_active on

extern "C" void fn_27_10FE78(void* self);
extern "C" void fn_27_110098(void* self);

extern "C" void fn_27_1102E0(void* self) {
    u8* p = (u8*)self;
    if (*(u8*)(p + 0x7C) == 1) {
        s32 v = *(s32*)(p + 0x4C);
        if (v < 0x7FFFFFFF) {
            *(s32*)(p + 0x4C) = v + 1;
        }
        fn_27_10FE78(self);
        fn_27_110098(self);
    }
}
