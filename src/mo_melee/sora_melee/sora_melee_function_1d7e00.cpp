#include <types.h>
#pragma force_active on

struct Foo
{
    u32 a;
    u32 b;
    union {
        struct {
            u32 low : 15;
            u32 b : 1;
            u32 high : 16;
        } bits;
        u32 raw;
    } c;
};

extern "C" u32 fn_27_1D7E00(Foo* p)
{
    return p->c.bits.b;
}
