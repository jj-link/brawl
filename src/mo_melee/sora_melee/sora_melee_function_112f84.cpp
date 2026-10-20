#include <types.h>
#pragma force_active on

struct Pair8 {
    u32 a;
    u32 b;
};

extern "C" void fn_27_112F84(u8* dst, const Pair8* src) {
    *(u32*)(dst + 0x404) = src->a;
    *(u32*)(dst + 0x408) = src->b;
}
