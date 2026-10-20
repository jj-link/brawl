#include <types.h>
#pragma force_active on

extern "C" void fn_27_150A7C(u8* self, int flag) {
    *(u8*)(self + 0x168) = flag;
    if (flag != 0) {
        return;
    }
    *(int*)(self + 0x150) = -1;
    *(int*)(self + 0x154) = -1;
    *(int*)(self + 0x158) = 0;
}
