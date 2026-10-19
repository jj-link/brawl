#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

extern "C" {

void *fn_73_986C(void *obj, u32 val1, u32 val2)
{
    u32 *p = (u32 *)((char *)obj + 0x6CC);
    *p = val1;
    *(((u32 *)((char *)obj + 0x6D4))) = val2;
    return obj;
}

}
