#pragma force_active on
typedef int s32;
typedef unsigned int u32;
extern s32 lbl_805A0C74;
u32 OSDisableInterrupts(void);
void OSRestoreInterrupts();

s32 fn_8021A658(void) {
    s32 temp_r31;

    OSDisableInterrupts();
    temp_r31 = lbl_805A0C74;
    OSRestoreInterrupts();
    return temp_r31;
}
