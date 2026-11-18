#include <types.h>
#pragma force_active on

extern "C" int fn_80053F4C(u8* p) {
    int max = 0;
    if (p[2] == 1) {
        u8* q = p + 0x12d8;
        for (int i = 0; i < 3; i++, q += 0x30) {
            if (q[0x2e] != 0 && q[0x2c] > max) max = q[0x2c];
        }
    } else {
        u8* q = p + 0x24;
        for (int i = 0; i < 4; i++, q += 0x2ac) {
            if (q[1] != 3 && q[0xe] > max) max = q[0xe];
        }
    }
    return max;
}
