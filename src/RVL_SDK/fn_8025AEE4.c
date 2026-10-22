#include <types.h>
#include <stddef.h>
#pragma force_active on

extern u8 lbl_8052D9C0[];

void *fn_8025AEE4(u32 arg0) {
    u8 *p = lbl_8052D9C0 + 0x3C;

    if (p[0] != 0 && *(u16 *)(p + 0x22) == arg0) {
        return p;
    }
    if ((p += 0x478)[0] != 0 && *(u16 *)(p + 0x22) == arg0) {
        return p;
    }
    if ((p += 0x478)[0] != 0 && *(u16 *)(p + 0x22) == arg0) {
        return p;
    }
    if ((p += 0x478)[0] != 0 && *(u16 *)(p + 0x22) == arg0) {
        return p;
    }
    return NULL;
}
