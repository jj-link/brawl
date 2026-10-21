#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

int fn_801E9C9C(void) {
    int level;
    unsigned int temp_r31;

    level = OSDisableInterrupts();
    temp_r31 = *(unsigned short *)0xCC00206E & 3;
    OSRestoreInterrupts(level);
    return temp_r31 & 1;
}
