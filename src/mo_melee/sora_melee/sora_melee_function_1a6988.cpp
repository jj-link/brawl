#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} fn_27_1A6988_t;

extern "C" void fn_27_1A6988(fn_27_1A6988_t* p)
{
    p->flags |= 2;
}
