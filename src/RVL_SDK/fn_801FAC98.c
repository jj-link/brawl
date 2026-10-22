#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

s32 DVDGetCommandBlockStatus(s32);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
extern char DummyCommandBlock_804E4260[];
extern s32 FatalErrorFlag_805A090C;
extern s32 PausingFlag_805A0908;
extern s32 executing_805A0990;

s32 DVDGetDriveStatus(void) {
    s32 temp_r31;
    s32 var_r30;
    s32 var_r3;

    temp_r31 = OSDisableInterrupts();
    if (FatalErrorFlag_805A090C != 0) {
        var_r30 = -1;
    } else if (PausingFlag_805A0908 != 0) {
        var_r30 = 8;
    } else if (executing_805A0990 == 0) {
        var_r30 = 0;
    } else {
        if ((u32)executing_805A0990 == (u32)DummyCommandBlock_804E4260) {
            var_r3 = 0;
        } else {
            var_r3 = DVDGetCommandBlockStatus(executing_805A0990);
        }
        var_r30 = var_r3;
    }
    OSRestoreInterrupts(temp_r31);
    return var_r30;
}
