#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

typedef struct Unk {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    u32 unk14;
    u32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Unk;

s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void fn_801D76BC(void *, u32);
void fn_801F9688(void);
s32 fn_801FB704(s32, Unk *);
extern s32 executing_805A0990;
extern s32 lbl_805A0904;
extern s32 lbl_8059EADC;

s32 fn_801FA940(Unk *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_r31;
    s32 temp_r30;

    arg0->unk8 = 1;
    arg0->unk18 = arg1;
    arg0->unk14 = arg2;
    arg0->unk10 = arg3;
    arg0->unk20 = 0;
    arg0->unk28 = arg4;
    if (lbl_8059EADC != 0) {
        if (arg0->unk8 == 1 || arg0->unk8 == 4 || arg0->unk8 == 5 || arg0->unk8 == 0x21 || arg0->unk8 == 0xE) {
            fn_801D76BC((void *)arg0->unk18, arg0->unk14);
        }
    }
    temp_r30 = OSDisableInterrupts();
    arg0->unkC = 2;
    temp_r31 = fn_801FB704(arg5, arg0);
    if (executing_805A0990 == 0 && lbl_805A0904 == 0) {
        fn_801F9688();
    }
    OSRestoreInterrupts(temp_r30);
    return temp_r31;
}