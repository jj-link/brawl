#include <types.h>
#pragma force_active on

extern void fn_802404EC(u8 *a, u8 *b, u32 mode);
extern void fn_8023E900(u8 *a, u8 *b, u32 mode);

void fn_80242B70(u8 *arg0) {
    u8 buf[10];
    u32 mode;

    buf[9] = arg0[0];
    buf[8] = arg0[1];
    buf[7] = arg0[2];
    buf[6] = arg0[3];
    buf[5] = arg0[4];
    buf[4] = arg0[5];
    buf[2] = arg0[6];
    buf[1] = arg0[7];
    buf[0] = arg0[8];
    mode = arg0[9];

    if (mode == 1) {
        fn_802404EC(&buf[4], &buf[0], mode);
        return;
    }
    fn_8023E900(&buf[4], &buf[0], mode);
}
