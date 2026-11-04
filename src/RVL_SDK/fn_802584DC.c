#include <string.h>
#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern void *fn_8022EFF8(int);
extern void fn_80259FF4(void *, int);
extern u8 *fn_802583F0(u8 *, u16, void *);
extern void fn_8024ABC4(u16, void *);
extern void fn_80231FB0(void *, int, int);
extern u8 lbl_8052D9C0[];

void fn_802584DC(u8 *self, int len, const void *data)
{
    u8 *size, *base, *packet, *p, *info;
    int n;
    packet = fn_8022EFF8(2);
    if (packet == 0) {
        fn_80259FF4(self, 6);
        return;
    }
    base = packet + 0x11;
    *(u16 *)(packet + 4) = 9;
    size = base + 3;
    packet[0x11] = 2;
    base[1] = *(u16 *)(self + 0x470) >> 8;
    base[2] = *(u16 *)(self + 0x470);
    info = *(u8 **)(self + 0x410);
    *(u16 *)(self + 0x470) = *(u16 *)(self + 0x470) + 1;
    p = fn_802583F0(size + 2, *(u16 *)(info + 0xc), info + 0x10);
    p[0] = *(u16 *)(lbl_8052D9C0 + 0x462e) >> 8;
    p[1] = *(u16 *)(lbl_8052D9C0 + 0x462e);
    p[2] = len;
    p += 3;
    if (len != 0 && data != 0) {
        memcpy(p, data, len);
        p += len;
    }
    n = p - size - 2;
    size[0] = (unsigned int)n >> 8;
    size[1] = n;
    self[0x474] = 1;
    *(u16 *)(packet + 2) = p - base;
    fn_8024ABC4(*(u16 *)(self + 0x22), packet);
    fn_80231FB0(self + 8, 5, 30);
}