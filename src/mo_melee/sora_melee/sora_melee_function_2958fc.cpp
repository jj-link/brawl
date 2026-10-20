#include <types.h>
#pragma force_active on

struct FnObj27 {
    u32 pad[2];
    u32 f : 6;
    u32 rest : 26;
};

extern "C" {
void fn_27_2958FC(FnObj27 *obj, u32 v)
{
    obj->f = v;
}
}
