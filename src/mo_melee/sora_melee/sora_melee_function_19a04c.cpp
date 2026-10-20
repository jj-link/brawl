#include <types.h>
#pragma force_active on

struct FieldBits {
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
};

extern "C" void fn_27_19A04C(void* p, u32 v)
{
    FieldBits* b = (FieldBits*)((u8*)p + 8);
    b->f = v;
}
