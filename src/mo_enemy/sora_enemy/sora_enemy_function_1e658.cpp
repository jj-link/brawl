#include <types.h>
#pragma force_active on

extern "C" float fn_41_1E658(float a, float b)
{
    if ((s32)b == 0x8bcf) {
        return a;
    }
    if ((s32)b == 0x8bd3) {
        return a;
    }
    if (a < b) {
        a = b;
    }
    return a;
}
