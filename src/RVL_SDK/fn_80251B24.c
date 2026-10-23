#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_8052D5A8[];

void *fn_80251B24(u32 arg0) {
    u8 *p;
    u8 *base;
    s32 odd;
    s32 prev;
    u16 i;
    u8 v;
    u8 *q;

    base = lbl_8052D5A8;
    odd = arg0 & 1;
    prev = (s32)arg0 - 1;

    for (i = 0; i < 5; i++) {
        p = base + i * 0xA4;
        q = p + 0x68;

        if (p[0x69] != 0) {
            if (*(u32 *)(q + 0x6C) == 0) {
                v = q[0xD];
                if (v == arg0) {
                    return q;
                }
                if (odd != 0 && (s32)v == prev) {
                    q[0xD] = v + 1;
                    return q;
                }
            }
        }
    }

    return 0;
}
