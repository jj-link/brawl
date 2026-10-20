#include <types.h>
#pragma force_active on

struct __attr {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" u32 fn_27_CFA0C(const void *ptr) {
    const __attr *s = (const __attr *)ptr;
    return (s->c >> 22) & 1;
}
