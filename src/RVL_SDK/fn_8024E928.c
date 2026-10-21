#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_8052CDC0[];
extern char lbl_80483DB0[];

extern u8 *fn_8024E864(u16, u16, int, u32);
extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);

void fn_8024E928(void *self, u32 type, u32 arg, u32 a, u32 b)
{
    u16 size;
    u8 *packet;
    u8 *p;

    if (type == 1)
        size = 2;
    else
        size = type == 2 ? 4 : 0;

    packet = fn_8024E864(*(u16 *)((u8 *)self + 0x28),
                         size + 2, 1, arg);
    if (packet == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, lbl_80483DB0);
    } else {
        packet[0x14] = type;
        packet[0x15] = type >> 8;
        p = packet + 0x16;

        if (size >= 2) {
            p[0] = a;
            p[1] = a >> 8;
            p += 2;
        }

        if (size >= 4) {
            p[0] = b;
            p[1] = b >> 8;
        }

        fn_8024CB94(self, 0, packet);
    }
}
