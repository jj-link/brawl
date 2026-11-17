#include <types.h>

#pragma force_active on

extern "C" void fn_27_249E78(void *unused, s32 n, u8 *buf) {
    s32 j;
    s32 i;
    s32 k;
    u8 tmp[100];

    if (n >= 100) {
        k = n % 100;
        for (i = k, j = 0; i < 100; ++j, ++i) {
            tmp[j] = buf[i];
        }
        for (i = 0; i < k; ++i, ++j) {
            tmp[j] = buf[i];
        }
        for (i = 0; i < 100; ++i) {
            buf[i] = tmp[i];
        }
    }
}
