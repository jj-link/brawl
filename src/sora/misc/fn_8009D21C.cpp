#include <types.h>
#pragma force_active on

struct FnSrc {
    u32 a;
    u32 b;
    u32 c;
    f32 d;
    u32 e;
    u32 f;
};

struct FnDst {
    u8 pad[0x110];
    u32 a;
    u32 b;
    u32 c;
    f32 d;
    u32 e;
    u32 f;
};

extern "C" void fn_8009D21C(FnDst* dst, const FnSrc* src)
{
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
}
