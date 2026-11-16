#include <types.h>
#pragma force_active on

extern void *fn_8022EFF8(u32);
extern void fn_80242908(void *);
typedef struct { u8 bytes[10]; } Buffer;
extern Buffer lbl_8040D9B0;

static inline void clear_range(u8 *buf, s32 start, s32 end) {
    s32 i;
    for (i = start; i <= end; i++) {
        buf[i / 8] &= ~(1 << (i % 8));
    }
}

s32 fn_80246A34(u32 arg0, u32 arg1) {
    u8 buf[10];
    u8 *p;
    u8 *src;

    *(Buffer *)buf = lbl_8040D9B0;

    p = (u8 *)fn_8022EFF8(2);
    if (p == 0) return 0;
    *(u16 *)(p + 2) = 13;
    *(u16 *)(p + 4) = 0;
    p[8] = 63;
    p[9] = 12;
    p[10] = 10;

    if (arg0 <= arg1 && arg1 <= 0x4E) {
        clear_range(buf, arg0, arg1);
    }

    {
        int j;
        for (j = 0; j < 10; j++) p[11 + j] = buf[j];
    }
    fn_80242908(p);
    return 1;
}