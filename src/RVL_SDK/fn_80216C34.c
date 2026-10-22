#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

int fn_80216C34(int arg) {
    int level;
    int ret;

    level = OSDisableInterrupts();
    ret = (*(unsigned char*)0x800030E3 >> 6) & 1;
    *(unsigned char*)0x800030E3 &= ~0x40;
    if (arg != 0) {
        *(unsigned char*)0x800030E3 |= 0x40;
    }
    OSRestoreInterrupts(level);
    return ret;
}
