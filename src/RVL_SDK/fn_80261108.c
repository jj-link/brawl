#include <types.h>
#pragma force_active on

s32 fn_80261108(s32 offset, u32 *stream)
{
    if (offset >= 0) {
        if ((s32)(stream[4] - stream[3]) >= offset) {
            stream[3] += offset;
            if (stream[4] <= stream[3]) {
                return -0x90;
            }
        } else {
            return -0x90;
        }
    } else {
        s32 amount = -offset;
        if ((s32)(stream[3] - stream[2]) >= amount) {
            stream[3] -= amount;
        } else {
            return -0x90;
        }
    }
    return 0;
}
