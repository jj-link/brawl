#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A5854(void* ptr) {
    struct S { u32 a : 12; u32 b : 1; u32 c : 19; };
    struct S* s = reinterpret_cast<struct S*>(static_cast<u8*>(ptr) + 8);
    s->b = 0;
}
