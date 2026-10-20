#include <types.h>
#pragma force_active on

typedef struct FnS27D379C {
    u32 pad0;
    u32 pad1;
    u32 w;
} FnS27D379C;

extern "C" {
s32 fn_27_D379C(FnS27D379C *s)
{
    return (s32)((s->w >> 16) << 26) >> 27;
}
}
