#include <types.h>
#pragma force_active on

extern void fn_8023EAE0(int, u8 *, u16, void *);
extern void *memcpy(void *, const void *, unsigned long);

void fn_80242CFC(u8 *arg0) {
    struct {
        u16 h[2];
        u8 dst[6];
        u8 b9, b10, b11, b16;
    } data;
    u8 buf[6];
    int r31;
    u16 id;

    r31 = arg0[0];
    id = (u16)(arg0[1] + (arg0[2] << 8));
    buf[5] = arg0[3];
    buf[4] = arg0[4];
    buf[3] = arg0[5];
    buf[2] = arg0[6];
    buf[1] = arg0[7];
    buf[0] = arg0[8];
    data.b9 = arg0[9];
    data.b10 = arg0[10];
    data.b11 = arg0[11];
    data.h[0] = (u16)(arg0[12] + (arg0[13] << 8));
    data.h[1] = (u16)(arg0[14] + (arg0[15] << 8));
    data.b16 = arg0[16];
    memcpy(data.dst, buf, 6);
    fn_8023EAE0(r31, buf, id, &data);
}
