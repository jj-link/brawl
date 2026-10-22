#pragma force_active on
#pragma global_optimizer off

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern char *strcpy(char *dst, const char *src);
extern char lbl_8047C120[];
extern int lbl_805A0BA8;

int fn_8020D310(char *arg0)
{
    int level;
    int ready;

    if (lbl_805A0BA8 == 2) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        return -0x80;
    }

    level = OSDisableInterrupts();
    strcpy(arg0, lbl_8047C120);
    OSRestoreInterrupts(level);
    return 0;
}
