#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 lbl_805A0C1C;
extern s32 lbl_8059ECD0;
extern void *fn_802137A4(s32, s32, s32);
extern s32 fn_80212C08(s32, s32, s32, s32, s32, s32, void (*)(void), void *);
extern void fn_80213C80(void);

s32 fn_80215368(s32 arg0, s32 arg1) {
    u8 *temp_r3;

    temp_r3 = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (lbl_8059ECD0 < 0) {
        return -0x65;
    }
    *(s32 *)(temp_r3 + 0x100) = arg0;
    *(s32 *)(temp_r3 + 0x104) = arg1;
    *(s32 *)(temp_r3 + 0x108) = 0;
    return fn_80212C08(lbl_8059ECD0, 0xd, 0, 0, 0, 0, fn_80213C80, temp_r3);
}
