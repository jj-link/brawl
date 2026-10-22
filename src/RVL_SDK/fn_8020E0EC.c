#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;

extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void OSRegisterVersion(s32);
extern s32 fn_801D536C(void);
extern void fn_801E0704(void *p);
extern s32 fn_8020CDB8(void);
extern s32 fn_8020E2A8(void *p, s32 a, s32 b);
extern u8 lbl_804ED380[];
extern u8 lbl_804ED520[];
extern s32 lbl_8059EB80;
extern s8 lbl_805A0BB8;
extern s8 lbl_805A0BCC;
extern u8 lbl_805A0BCE;

void fn_8020E0EC(void) {
    OSDisableInterrupts();
    if (lbl_805A0BCE != 0) {
        OSRestoreInterrupts();
        return;
    }
    lbl_805A0BCE = 1;
    lbl_805A0BB8 = 1;
    OSRestoreInterrupts();
    OSRegisterVersion(lbl_8059EB80);
    fn_801E0704(lbl_804ED380);
    if (fn_801D536C() & 0x10000000) {
        lbl_805A0BCC = 1;
    }
    if ((fn_8020CDB8() != 0) || (fn_8020E2A8(lbl_804ED520, 0x4000, 0) != 0)) {
        lbl_805A0BB8 = 2;
    }
}
