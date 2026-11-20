#include <types.h>
#pragma force_active on

extern void fn_80241644(u8 *a, void *b, u8 c);

void fn_802434CC(u8 *arg0) {
    u8 *p = arg0 + 22;
    u8 a[8];
    u8 b[16];

    a[5] = arg0[0];
    a[4] = arg0[1];
    a[3] = arg0[2];
    a[2] = arg0[3];
    a[1] = arg0[4];
    a[0] = arg0[5];
    b[15] = arg0[6];
    b[14] = arg0[7];
    b[13] = arg0[8];
    b[12] = arg0[9];
    b[11] = arg0[10];
    b[10] = arg0[11];
    b[9] = arg0[12];
    b[8] = arg0[13];
    b[7] = arg0[14];
    b[6] = arg0[15];
    b[5] = arg0[16];
    b[4] = arg0[17];
    b[3] = arg0[18];
    b[2] = arg0[19];
    b[1] = arg0[20];
    b[0] = arg0[21];
    fn_80241644(a, b, **(u8 **)&p);
}