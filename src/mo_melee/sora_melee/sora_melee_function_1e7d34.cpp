#include <types.h>
#pragma force_active on

struct BitObj {
    u32 pad[2];
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" void fn_27_1E7D34(BitObj *obj, u32 val)
{
    obj->b = val;
}
