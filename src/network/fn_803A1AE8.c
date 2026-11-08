#include <types.h>
#pragma force_active on
s32 fn_8039A260(void);
s32 fn_8039A274(void);
s32 fn_803A1DF4(void **);
s32 fn_803A1AE8(s32 *arg0) {
    void *data;
    s32 result;
    s32 count = 0;
    u32 i, j;
    u32 *p;
    u32 bits;
    if (fn_8039A260() == 0 && fn_8039A274() == 0)
        return -9;
    *arg0 = 0;
    result = fn_803A1DF4(&data);
    if (result != 0)
        return result;
    p = (u32 *)data;
    for (i = 0; i < 4; i++) {
        bits = p[i + 4];
        for (j = 0; j < 32; j++) {
            if (bits & 1)
                count++;
            bits >>= 1;
        }
    }
    *arg0 = count;
    return 0;
}