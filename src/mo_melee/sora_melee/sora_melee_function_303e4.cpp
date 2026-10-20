#include <types.h>
#pragma force_active on

extern "C" void fn_27_2F00C(u8* p, u32 bit, u32 flag);
extern "C" void fn_80133F64(void* p);

extern "C" void fn_27_303E4(void* unused, u8* p) {
    u8* q = *(u8**)(p + 4);
    q[0x71] = (u8)(q[0x71] & ~0x08);
    q[0x72] = (u8)(q[0x72] & ~0x20);
    fn_27_2F00C(p, 0, 1);
    if ((*(s32*)(q + 8) >> 24) != 0) {
        fn_80133F64(q);
    }
}
