#include <types.h>
#pragma force_active on

extern u8 *fn_8025BA20(u8 *, u8, u32 *);
extern u8 fn_8025BBD0(u8 *, u32, s32, s32);

u8 fn_80257860(u8 *p, u32 size, s32 arg2, s32 arg3, s32 depth)
{
    u32 length;
    u8 *end = p + size;
    u8 first;
    u32 type;

    if (depth > 3) {
        return 0;
    }

    while (p < end) {
        first = *p;
        p = fn_8025BA20(p + 1, first, &length);
        type = (first >> 3) & 0x1F;
        if (type == 3) {
            if (fn_8025BBD0(p, length, arg2, arg3)) {
                return 1;
            }
        } else if (type == 6) {
            if (fn_80257860(p, length, arg2, arg3, depth + 1)) {
                return 1;
            }
        }
        p += length;
    }
    return 0;
}
