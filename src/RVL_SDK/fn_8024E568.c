#include <types.h>
#pragma force_active on
extern void *memset(void *, int, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_8024CE60(void);
extern unsigned char lbl_8052CDC0[];

void *fn_8024E568(void *arg0)
{
    unsigned char *p = lbl_8052CDC0 + 8;
    int i;
    for (i = 4; i > 0; i--) {
        if (p[0] == 0) {
            u16 counter;
            memset(p, 0, 0x5c);
            p[0] = 1;
            memcpy(p + 0x2a, arg0, 6);
            *(s32 *)(p + 4) = 0;
            *(u16 *)(p + 0x28) = 0xffff;
            *(s32 *)(p + 0x50) = 0;
            *(u16 *)(p + 0x32) = 0xffff;
            *(void **)(p + 0x20) = p;
            *(u16 *)(p + 0x38) = 0;
            *(u16 *)(p + 0x58) = *(u16 *)(lbl_8052CDC0 + 0x7ba);
            p[0x31] = 0;
            counter = *(u16 *)(lbl_8052CDC0 + 0x7b8);
            *(u16 *)(lbl_8052CDC0 + 0x7b8) = (u16)(counter + 1);
            fn_8024CE60();
            return p;
        }
        p += 0x5c;
    }
    return 0;
}