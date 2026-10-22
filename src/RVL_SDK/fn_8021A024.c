#pragma force_active on
extern void *lbl_804F6810[];
extern unsigned int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);

int fn_8021A024(int arg0, int *arg1) {
    unsigned char *obj = (unsigned char *)lbl_804F6810[arg0];
    int result;

    OSDisableInterrupts();
    if (arg1 != 0) {
        *arg1 = obj[0x8C1];
    }
    result = *(int *)(obj + 0x8BC);
    if (result != -1) {
        if (obj[0x8C1] == 0xFD) {
            result = -1;
        } else if (*(int *)(obj + 0x8DC) == 0) {
            result = -2;
        }
    }
    OSRestoreInterrupts();
    return result;
}
