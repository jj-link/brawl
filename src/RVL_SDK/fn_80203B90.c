#include <types.h>
#pragma force_active on
void *memset(void *, int, unsigned long);
s32 fn_80203B90(u32 *arg0) {
    u32 *var_r29;
    u32 var_r28;

    var_r29 = arg0;
    var_r28 = 0;
    do {
        if (var_r29[19] >= 100) {
            return 0;
        }
        if (var_r29[22] > 100) {
            return 0;
        }
        if (var_r29[0] == 0) {
            return 0;
        }
        memset((void *) var_r29[0], 0, var_r29[6] * 4);
        var_r29[3] = 0;
        var_r28++;
        var_r29[9] = (s32) ((128.0f * (f32) var_r29[19]) / 100.0f);
        var_r29[12] = (s32) ((128.0f * (f32) var_r29[22]) / 100.0f);
        var_r29++;
    } while (var_r28 < 3);
    return 1;
}
