#include <types.h>
#pragma force_active on

extern "C" void fn_27_2F00C(u8*, u32, u32);
extern "C" void fn_80133F50();

extern "C" void fn_27_30DAC(void*, u8* p) {
    fn_27_2F00C(p, 0, 1);
    u8* q = *(u8**)(p + 4);
    q[0x71] &= ~(1 << 3);
    q = *(u8**)(p + 4);
    q[0x72] &= ~(1 << 5);
    q = *(u8**)(p + 4);
    if (*(s32*)(q + 8) >> 24)
        fn_80133F50();
}
