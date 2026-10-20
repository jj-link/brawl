#include <types.h>
#pragma force_active on

struct FieldWord {
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" {
void fn_27_19D498(void* obj, unsigned long val)
{
    FieldWord* p = (FieldWord*)((char*)obj + 8);
    p->b = val;
}
}
