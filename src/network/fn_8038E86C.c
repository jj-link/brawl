#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern s32 fn_8038E9E8(char *, s32, s32);
extern void fn_8038EB7C(void);
extern char lbl_804912DC[];
extern OSMutex lbl_80536580;
extern u8 *lbl_805A113C;

s32 fn_8038E86C(s32 *arg0, s32 *arg1, s32 *arg2)
{
    s32 ret;
    s32 a = 0;
    s32 b = 0;
    s32 c = 0;
    u8 flags;
    s32 i;
    fn_8038EB7C();
    ret = fn_8038E9E8(lbl_804912DC, 0, 3);
    if (ret == 0) {
        for (i = 0; i < 3; i++) {
            flags = lbl_805A113C[i * 0x91c + 8];
            if (flags & 0x80) {
                if (flags & 1) {
                    a |= 1 << i;
                } else {
                    if (lbl_805A113C[i * 0x91c + 0x7ca] != 1)
                        b |= 1 << i;
                    if ((u8)*(s8 *)(lbl_805A113C + i * 0x91c + 0x7ca) == 1)
                        c |= 1 << i;
                }
            }
        }
    }
    OSUnlockMutex(&lbl_80536580);
    if (arg0 != 0) *arg0 = a;
    if (arg1 != 0) *arg1 = b;
    if (arg2 != 0) *arg2 = c;
    return ret;
}