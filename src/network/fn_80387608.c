#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

u8 fn_80387608(u8 *arg0, u32 arg1, u8 *arg2, u32 arg3, u8 *arg4, u32 *arg5) {
    u32 count;
    u32 mask;
    u32 v;

    if (arg1 == 0) {
        return 0;
    }

    count = 0;
    mask = 1;
    while (mask < arg1) {
        mask = (mask << 1) + 1;
    }

    do {
        *arg4 = arg0[*arg4] + arg2[(*arg5)++];
        if (*arg5 >= arg3) {
            *arg5 = 0;
            *arg4 = *arg4 + arg3;
        }

        count++;
        v = mask & *arg4;
        if (count > 11) {
            v %= arg1;
        }
    } while (v > arg1);

    return (u8)v;
}
