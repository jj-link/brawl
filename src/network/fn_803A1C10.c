#pragma force_active on
#include <types.h>

extern s32 fn_8039A260(void);
extern s32 fn_8039A274(void);
extern s32 fn_803A1DF4(void **);

s32 fn_803A1C10(u32 arg0)
{
    void *data;
    s32 result;
    u32 *p;

    if (fn_8039A260() == 0 && fn_8039A274() == 0)
        return -9;

    result = fn_803A1DF4(&data);
    if (result != 0)
        return result;

    p = data;
    if (arg0 >= p[2])
        return -3;

    p = (u32 *)((char *)data + arg0 * 8);
    return *(unsigned long long *)(p + 16) != 0;
}
