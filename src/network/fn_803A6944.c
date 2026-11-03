#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    unsigned char pad[0x30C];
    int error;
} SOThread;

extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern SOThread *fn_801E0714(void);
extern int lbl_805A11E4;

int fn_803A6944(int arg0, int arg1)
{
    int interrupts = OSDisableInterrupts();
    SOThread *thread = fn_801E0714();
    if (thread != 0) {
        thread->error = arg1;
    } else {
        lbl_805A11E4 = arg1;
    }
    OSRestoreInterrupts(interrupts);
    return arg1;
}
