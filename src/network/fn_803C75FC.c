#pragma force_active on
typedef unsigned int u32;
typedef int s32;

s32 fn_803C75FC(u32 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 q;

    q = arg1 / arg2;
    if (q < 0xFF5U) {
        if (arg0 != 0) {
            *arg0 = (arg3 + ((q * 4 - q) >> 1) - 1) / arg3;
        }
        return 0;
    }
    if (q < 0xFFF5U) {
        if (arg0 != 0) {
            *arg0 = (arg3 + (q * 2) - 1) / arg3;
        }
        return 1;
    }
    if (arg0 != 0) {
        *arg0 = (arg3 + (q * 4) - 1) / arg3;
    }
    return 2;
}
