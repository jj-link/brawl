#include <types.h>
#pragma force_active on

struct FieldWord {
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" void fn_27_1A261C(void* p, u32 v)
{
    FieldWord* w = (FieldWord*)((char*)p + 8);
    w->b = v;
}
