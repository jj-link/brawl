#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 level);
extern u32 lbl_805A0810;

u32 fn_801E9BDC(void) {
    s32 level;
    u32 temp_r31;

    level = OSDisableInterrupts();
    temp_r31 = lbl_805A0810;
    switch (temp_r31) {
    case 0:
    case 3:
    case 6:
    case 7:
        temp_r31 = 0;
        break;
    case 1:
    case 4:
        temp_r31 = 1;
        break;
    }
    OSRestoreInterrupts(level);
    return temp_r31;
}
