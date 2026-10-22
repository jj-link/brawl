#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_8026029C(u32, s32, u32);
extern s8 lbl_805A0E70;
extern u32 lbl_805A0E74;
extern s32 lbl_805A0E78;

s32 fn_8025FB38(s32 arg0, s32 arg1) {
    s32 temp_r31;
    u32 bit;
    u32 mask;

    temp_r31 = OSDisableInterrupts();
    bit = (lbl_805A0E74 >> 16) & 1;
    mask = (0 - bit) & 0x800;
    fn_8026029C(((mask + 0xD11000) << 6) & 0x3FFFFF00, arg0, (arg1 + 3) & 0xFFFFFFFC);
    lbl_805A0E78 = 0;
    lbl_805A0E70 = 0;
    OSRestoreInterrupts(temp_r31);
    return 0;
}
