#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 state);
extern void fn_80260074(u32 addr, void *buf, u32 size);
extern u8 lbl_805A0E70;
extern s32 lbl_805A0E74;
extern s32 lbl_805A0E78;

s32 fn_8025FA94(void) {
    u8 local1;
    s32 local2;
    s32 temp;

    lbl_805A0E70 = 0;
    if (lbl_805A0E78 == 0) {
        temp = OSDisableInterrupts();
        fn_80260074(0x34000000, &local1, 1);
        if (!(local1 & 8)) {
            fn_80260074(0x34000200, &local2, 4);
            if ((local2 & 0x1F000000) == 0x1F000000) {
                lbl_805A0E74 = local2;
                lbl_805A0E78 = local2 & 0x1FFF;
                lbl_805A0E70 = 1;
            }
        }
        OSRestoreInterrupts(temp);
    }
    return lbl_805A0E78;
}
