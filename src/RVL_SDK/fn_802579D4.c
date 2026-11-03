#include <types.h>
#pragma force_active on

extern u8 lbl_8052D9C0[];
extern void *memset(void *dst, int c, size_t n);
extern void fn_80257BC8(u32 a, int b, int c, int d, void *e, int f);

u32 fn_802579D4(void) {
    u8 *base = &lbl_8052D9C0[0x121c];
    int c;
    u32 val;
    u8 buf[4];

    if (*(u16 *)(base + 6) < 0x14) {
        memset(base + *(u16 *)(base + 6) * 0x298 + 8, 0, 0x298);
        if (*(u16 *)(base + 6)) {
            val = *(u32 *)(base + (*(u16 *)(base + 6) - 1) * 0x298 + 8) + 1;
        } else {
            val = 0x10000;
        }
        *(u32 *)(base + *(u16 *)(base + 6) * 0x298 + 8) = val;
        c = *(u16 *)(base + 6) + 1;
        *(u16 *)(base + 6) = (u16)c;
        buf[0] = (u8)(val >> 24);
        buf[1] = (u8)(val >> 16);
        buf[2] = (u8)(val >> 8);
        buf[3] = (u8)val;
        fn_80257BC8(val, 0, 1, 4, buf, c);
        return *(u32 *)(base + (*(u16 *)(base + 6) - 1) * 0x298 + 8);
    }
    return 0;
}
