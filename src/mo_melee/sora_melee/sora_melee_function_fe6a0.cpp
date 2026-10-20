#include <types.h>
#pragma force_active on

struct FieldWord {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_FE6A0(u32* p, u32 v)
{
    FieldWord* w = (FieldWord*)&p[2];
    w->b = v;
}
}
