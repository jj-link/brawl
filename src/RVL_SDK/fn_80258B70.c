#include <types.h>
#include <string.h>
#pragma force_active on

extern void *fn_8022EFF8(u32);
extern void fn_80259FF4(void *, u16);
extern u8 *fn_802583F0(u8 *, u16, void *);
extern void fn_8024ABC4(u16, void *);
extern void fn_80231FB0(void *, s32, s32);
extern u8 *fn_8025B020(u8 *, u16 *, u16);
extern u8 *fn_8025BA20(u8 *, u8, u32 *);
extern u8 *fn_80258E44(void *, u8 *, u8 *);
extern void fn_802319FC(u32, const char *, u8);
extern u8 lbl_8052D9C0[];
extern char lbl_80484CD0[];

void fn_80258B70(u8 *self, u8 *data)
{
    u16 len;
    u8 *base;
    u8 *packet;
    u8 *size;
    u8 *p;
    u8 *pp;
    u8 *q;
    u8 *tail;
    u8 *cur;
    u8 *end;
    u8 *t;
    u32 flag;
    u32 n;
    u32 sp8;
    u8 type;

    flag = 0;
    if (data != 0) {
        len = (u16)((data[4] << 8) + data[5]);
        data = data + 6;
        if ((s32)(*(u16 *)(self + 0x24) + len) > 0x3E8) {
            fn_80259FF4(self, 4);
            goto done;
        }
        memcpy(self + *(u16 *)(self + 0x24) + 0x26, data, len);
        *(u16 *)(self + 0x24) = *(u16 *)(self + 0x24) + len;
        data = data + len;
        if (*data != 0) {
            if (*data > 0x10) {
                fn_80259FF4(self, 5);
                goto done;
            }
            flag = 1;
        }
    }

    if (flag != 0 || data == 0) {
        packet = fn_8022EFF8(2);
        if (packet == 0) {
            fn_80259FF4(self, 6);
            goto done;
        }
        base = packet + 0x11;
        *(u16 *)(packet + 4) = 9;
        base[0] = 6;
        size = base + 3;
        base[1] = *(u16 *)(self + 0x470) >> 8;
        base[2] = *(u16 *)(self + 0x470);
        *(u16 *)(self + 0x470) = *(u16 *)(self + 0x470) + 1;
        p = fn_802583F0(size + 2, *(u16 *)(*(u8 **)(self + 0x410) + 0xc), *(u8 **)(self + 0x410) + 0x10);
        pp = p + 2;
        p[0] = *(u16 *)(lbl_8052D9C0 + 0x462c) >> 8;
        p[1] = *(u16 *)(lbl_8052D9C0 + 0x462c);
        if (*(u16 *)(*(u8 **)(self + 0x410) + 0x4c) != 0) {
            q = fn_8025B020(pp, (u16 *)(*(u8 **)(self + 0x410) + 0x4e), *(u16 *)(*(u8 **)(self + 0x410) + 0x4c));
        } else {
            q = fn_8025B020(pp, 0, 0);
        }
        if (data != 0) {
            memcpy(q, data, data[0] + 1);
            q = (u8 *)((u32)data[0] + (u32)q);
            tail = q + 1;
        } else {
            *q = 0;
            tail = q + 1;
        }
        n = (u32)(tail - size) - 2;
        size[0] = n >> 8;
        size[1] = n;
        *(u16 *)(packet + 2) = tail - base;
        fn_8024ABC4(*(u16 *)(self + 0x22), packet);
        fn_80231FB0(self + 8, 5, 0x1E);
        goto done;
    }

    type = self[0x26];
    p = self + 0x27;
    if ((type >> 3) != 6) {
        if (lbl_8052D9C0[0x4630] >= 2) {
            fn_802319FC(0xA0001, lbl_80484CD0, type);
        }
    } else {
        cur = fn_8025BA20(p, type, &sp8);
        end = (u8 *)((u32)self + *(u16 *)(self + 0x24) + 0x26);
        if (cur + sp8 != end) {
            fn_80259FF4(self, 5);
            goto done;
        }
        while (cur < end) {
            cur = fn_80258E44(self, cur, self + *(u16 *)(self + 0x24) + 0x26);
            if (cur == 0) {
                fn_80259FF4(self, 0x10000 - 12);
                goto done;
            }
        }
        fn_80259FF4(self, 0);
        goto done;
    }
done:
    return;
}