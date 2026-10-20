#include <types.h>
#pragma force_active on

struct W {
    unsigned : 15;
    unsigned v : 1;
    unsigned : 16;
};

extern "C" u32 fn_27_1CFDA4(void *obj)
{
    return (*(struct W *)((u8 *)obj + 8)).v;
}
