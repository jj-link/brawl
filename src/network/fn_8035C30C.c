#include <string.h>
#include <types.h>
#pragma force_active on

struct sockaddr {
    s16 unk0;
    u16 unk2;
};

extern s32 lbl_805A1044;
s32 SOBind(s32, s8 *);

s32 bind(s32 arg0, const struct sockaddr *arg1, s8 arg2) {
    s8 sp8[8];
    s32 temp_r3;

    if (arg1->unk2 == 0) {
        return 0;
    }
    memcpy(sp8, arg1, 8);
    sp8[0] = arg2;
    temp_r3 = SOBind(arg0, sp8);
    if (temp_r3 >= 0) {
        return temp_r3;
    }
    lbl_805A1044 = temp_r3;
    return -1;
}
