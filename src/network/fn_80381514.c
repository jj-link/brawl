#pragma force_active on
typedef unsigned char u8;
typedef int s32;

s32 fn_8035C658(s32);
s32 fn_8035C660(s32, s32 *, s32, s32 *);
void fn_8037BDD4(void *, s32, s32);

void fn_80381514(void *arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r3;
    u8 *self = (u8 *)arg0;

    temp_r3 = fn_8035C660(*(s32 *)(self + 0x4c), &spC, 0, &sp8);
    if ((temp_r3 == -1) || ((temp_r3 == 1) && (sp8 != 0))) {
        *(s32 *)(self + 0x120) = 1;
        *(s32 *)(self + 0x3c) = 5;
        if (temp_r3 == -1) {
            *(s32 *)(self + 0x50) = fn_8035C658(*(s32 *)(self + 0x4c));
            return;
        }
        *(s32 *)(self + 0x50) = 0;
        return;
    }
    if ((temp_r3 == 1) && (spC != 0)) {
        *(s32 *)(self + 0x10) = 8;
        fn_8037BDD4(self, 0, 0);
    }
}
