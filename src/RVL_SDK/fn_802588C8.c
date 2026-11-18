#include <types.h>
#include <string.h>
#pragma force_active on
extern void *fn_8022EFF8(u32);
extern void fn_80259FF4(void *, u16);
extern u8 *fn_80258E44(u8 *, u8 *, u8 *);
extern u8 *fn_8025B020(u8 *, u16 *, u16);
extern int fn_8024ABC4(int, u8 *);
extern void fn_80231FB0(void *, short, int);
extern struct { u8 pad[0x462c]; u16 value; } lbl_8052D9C0;
void fn_802588C8(u8 *self, u8 *input)
{
    u8 *base, *size;
    int has_data = 0;
    u8 *packet, *p, *info;
    u16 len;
    int n;
    if (input != 0) {
        len = (input[4] << 8) + input[5];
        input += 6;
        if (*(u16 *)(self + 0x24) + len > 1000) {
            fn_80259FF4(self, 4);
            return;
        }
        memcpy(self + 0x26 + *(u16 *)(self + 0x24), input, len);
        *(u16 *)(self + 0x24) += len;
        input += len;
        if (*input != 0) {
            if (*input > 16) {
                fn_80259FF4(self, 5);
                return;
            }
            has_data = 1;
        } else {
            if (!fn_80258E44(self, self + 0x26, self + 0x26 + *(u16 *)(self + 0x24))) {
                fn_80259FF4(self, 0xfff4);
                return;
            }
            *(u16 *)(self + 0x24) = 0;
            *(u16 *)(self + 0x46e) += 1;
        }
    }
    if (*(u16 *)(self + 0x46e) < *(u16 *)(self + 0x46c)) {
        packet = fn_8022EFF8(2);
        if (packet == 0) {
            fn_80259FF4(self, 6);
            return;
        }
        *(u16 *)(packet + 4) = 9;
        base = packet + 0x11;
        base[0] = 4;
        p = base + 3;
        size = p;
        base[1] = *(u16 *)(self + 0x470) >> 8;
        base[2] = *(u16 *)(self + 0x470);
        *(u16 *)(self + 0x470) += 1;
        p += 2;
        *p++ = *(u32 *)(self + 0x418 + *(u16 *)(self + 0x46e) * 4) >> 24;
        *p++ = *(u32 *)(self + 0x418 + *(u16 *)(self + 0x46e) * 4) >> 16;
        *p++ = *(u32 *)(self + 0x418 + *(u16 *)(self + 0x46e) * 4) >> 8;
        *p++ = *(u32 *)(self + 0x418 + *(u16 *)(self + 0x46e) * 4);
        *p++ = lbl_8052D9C0.value >> 8;
        *p++ = lbl_8052D9C0.value;
        info = *(u8 **)(self + 0x410);
        if (*(u16 *)(info + 0x4c))
            p = fn_8025B020(p, (u16 *)(info + 0x4e), *(u16 *)(info + 0x4c));
        else
            p = fn_8025B020(p, 0, 0);
        if (has_data) {
            memcpy(p, input, *input + 1);
            p += *input + 1;
        } else {
            *p++ = 0;
        }
        n = p - size - 2;
        size[0] = (unsigned int)n >> 8;
        size[1] = n;
        *(u16 *)(packet + 2) = p - base;
        fn_8024ABC4(*(u16 *)(self + 0x22), packet);
        fn_80231FB0(self + 8, 5, 30);
    } else {
        fn_80259FF4(self, 0);
    }
}
