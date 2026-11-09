#include <types.h>
#pragma force_active on

extern u8 lbl_8052CDC0[];
extern u8 lbl_80529CF8[];
extern const char lbl_80483E2C[];
extern const char lbl_8059EE18[5];
extern const char lbl_8059EE20[6];

extern int fn_8023F304(const void *);
extern void fn_802319FC(s32, const char *, const char *);
extern void fn_802383DC(const void *, s32, s32);
extern void fn_80231FB0(void *, s32, s32);
extern s32 fn_802501E4(void *);

s32 fn_802500CC(void *arg0) {
    s32 i;
    u8 *ptr;
    s32 result;

    ((s32 *)arg0)[1] = 3;
    ptr = &lbl_8052CDC0[8];

    for (i = 0; i < 4; i++) {
        if (ptr != (u8 *)arg0 && ptr[0] != 0 && ptr[0x30] == 1) {
            result = fn_8023F304((const void *)(ptr + 0x2A));
            if (lbl_8052CDC0[0] >= 3) {
                fn_802319FC(0x80002, lbl_80483E2C, ((u8)result == 1) ? lbl_8059EE18 : lbl_8059EE20);
            }
            if ((u8)result != 1 && (lbl_80529CF8[0x640] & 0x20)) {
                ((s32 *)arg0)[1] = 2;
                ((u8 *)arg0)[0x30] = 0;
                fn_802383DC((const void *)(ptr + 0x2A), 0, 0);
                fn_80231FB0((u8 *)arg0 + 0x10, 2, 0xA);
                return 1;
            }
        }
        ptr += 0x5C;
    }
    return fn_802501E4(arg0);
}
