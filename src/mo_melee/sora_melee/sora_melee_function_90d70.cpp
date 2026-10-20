#include <types.h>
#pragma force_active on

typedef struct FnPair {
    u32 a;
    u32 b;
} FnPair;

extern "C" void fn_27_90D70(FnPair* dst, const FnPair* src, u32 v)
{
    dst->a = src->a;
    dst->b = v;
}
