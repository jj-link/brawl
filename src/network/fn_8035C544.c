#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 SOSendTo(s32, s32, s32, s32, void *);
extern void *memcpy(void *, const void *, unsigned long);
extern s32 lbl_805A1044;

s32 sendto(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, u8 arg5) {
    u8 sp8[8];
    s32 temp_r3;

    memcpy(sp8, arg4, 8);
    sp8[0] = arg5;
    temp_r3 = SOSendTo(arg0, arg1, arg2, arg3, sp8);
    if (temp_r3 >= 0) {
        return temp_r3;
    }
    lbl_805A1044 = temp_r3;
    return -1;
}
