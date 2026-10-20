#include <types.h>
#pragma force_active on
extern "C" u32 fn_27_1A2DBC(struct s *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    return (v & 0x02000000) != 0;
}
