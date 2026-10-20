#include <types.h>
#pragma force_active on

struct ftKindFlags
{
    u32 a;
    u32 b;
    s32 c : 3;
};

extern "C" int fn_27_19F064(const ftKindFlags* p)
{
    return p->c;
}
