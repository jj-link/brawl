#pragma force_active on
int OSDisableInterrupts(void);
void OSRestoreInterrupts(int);
extern void (*lbl_8059EB24)(void *);

void fn_80203980(int *arg0) {
    unsigned int i;
    int irq;

    irq = OSDisableInterrupts();
    arg0[15] = arg0[15] | 1;
    for (i = 0; i < 3; i++) {
        if (arg0[i] != 0) {
            lbl_8059EB24((void *)arg0[i]);
            arg0[i] = 0;
        }
    }
    OSRestoreInterrupts(irq);
}
