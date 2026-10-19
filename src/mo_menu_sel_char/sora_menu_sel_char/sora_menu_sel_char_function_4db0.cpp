#include <types.h>
#pragma force_active on

extern "C" void fn_10_13CAC(void* param);

extern "C" void fn_10_4DB0(u8* self) {
    u8* p = self;
    int i = 0;
    while (i < *(int*)(self + 0x648)) {
        fn_10_13CAC(*(void**)(p + 0x44));
        p += 4;
        ++i;
    }
}
