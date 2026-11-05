#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_80529CF8[];
extern char lbl_80480FD4[];
extern void fn_80231A2C(u32, const char *, u32, u32, u32);
extern void *fn_8022EFF8(u32);
extern void fn_80246444(void *, u16, u16);
extern void fn_80246414(void *, u8);

int fn_8023C248(u16 mode, u16 window, u16 interval)
{
    u8 *state = lbl_80529CF8;
    u8 flags = 0;
    void *packet;

    if (mode != 0 && (u32)mode != 1)
        return 5;
    if (lbl_80529CF8[0x64E] < 3)
        return 12;
    if (window == 0)
        window = 0x12;
    if (interval == 0)
        interval = 0x800;
    if (lbl_80529CF8[0x27C0] >= 3)
        fn_80231A2C(0xD0002, lbl_80480FD4, mode, window, interval);
    if ((u32)mode == 1) {
        if ((u32)window < 0x12 || (u32)window > 0x1000 ||
            (u32)interval < 0x12 || (u32)interval > 0x1000 ||
            (u32)window > (u32)interval)
            return 5;
        flags |= 2;
    }
    if ((u32)window != *(u16 *)(state + 0x169C) ||
        (u32)interval != *(u16 *)(state + 0x169E)) {
        packet = fn_8022EFF8(2);
        if (packet != 0) {
            *(u16 *)(state + 0x169C) = window;
            *(u16 *)(state + 0x169E) = interval;
            fn_80246444(packet, interval, window);
        } else {
            return 3;
        }
    }
    packet = fn_8022EFF8(2);
    if (packet != 0) {
        if (*(u16 *)(state + 0x1698) != 0)
            flags |= 1;
        *(u16 *)(state + 0x169A) = mode;
        fn_80246414(packet, flags);
    } else {
        return 3;
    }
    return 0;
}
