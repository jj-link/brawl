#include <types.h>
#pragma force_active on

struct fn_27_2EB900_obj {
    u8 pad0[8];
    u32 field : 3;
    u32 rest : 29;
};

extern "C" void fn_27_2EB900(fn_27_2EB900_obj* p, u32 v)
{
    p->field = v;
}
