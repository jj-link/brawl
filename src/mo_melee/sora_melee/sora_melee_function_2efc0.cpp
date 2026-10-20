#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[0x73];
    u8 a : 2;
    u8 b : 1;
    u8 c : 5;
};

extern "C" void fn_27_2EFC0(void* p, u32 v) {
    Inner* inner = *(Inner**)((u8*)p + 4);
    inner->b = v;
}
