#include <types.h>
#pragma force_active on

extern int fn_803F6150(const void*, const void*, unsigned long);
extern u8 lbl_80529CF8[];

s32 fn_8023DB4C(void* arg0, u8* arg1) {
    u8 i = 0;
    u8* p = lbl_80529CF8 + 0x34;
    u8* q;
    while (i < 4) {
        if (p[0x119] != 0 && fn_803F6150(p + 8, arg0, 6) == 0) {
            break;
        }
        i++;
        p += 0x11C;
    }
    if ((s32)(u8)i == 4) {
        return 7;
    }
    q = lbl_80529CF8 + (u8)i * 0x22;
    *arg1 = q[0x4EC];
    return 0;
}
