#include <types.h>
#pragma force_active on

typedef struct Blk { u8 b[9]; } Blk;

extern void fn_802319E4(u32, const char *);
extern u8 *fn_80251AD0(void *, u16);
extern u8 *fn_80251B24(u16);
extern void fn_80254830(void *, u16, Blk *, s32, u8);
extern u8 lbl_8052D5A8[];
extern char lbl_80483FD8[];

void fn_80250BB0(void *arg0, u16 arg1, Blk *arg2, s32 arg3)
{
    u8 *p;

    p = fn_80251AD0(arg0, arg1);
    if (lbl_8052D5A8[0x414] >= 4) {
        fn_802319E4(0x90003, lbl_80483FD8);
    }
    if (p == 0) {
        p = fn_80251B24(arg1);
        if (p == 0) {
            *(Blk *)(p + 0x51) = *arg2;
            fn_80254830(arg0, arg1, arg2, 0, p[0x57]);
            return;
        }
        ((u8 *)arg0 + arg1)[0x24] = *p;
    }
    *(Blk *)(p + 0x51) = *arg2;
    fn_80254830(arg0, arg1, arg2, arg3, p[0x57]);
}
