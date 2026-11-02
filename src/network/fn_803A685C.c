#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

typedef struct {
    int unknown0;
    void (*free)(int, void *, unsigned int);
    int state;
    int unknownC;
    void *buffer;
    int count;
} SOState;

extern SOState lbl_80537680;
extern unsigned char lbl_805A11E0;
extern int lbl_805A11E4;
extern OSThread *fn_801E0714(void);

int fn_803A685C(int unused, int *out)
{
    int result = 0;
    int interrupts;
    OSThread *thread;

    interrupts = OSDisableInterrupts();
    switch ((int)lbl_805A11E0) {
    case 0:
        result = -39;
        break;
    default:
    case 1:
        result = -28;
        break;
    case 2:
        if (lbl_80537680.state < 0) {
            result = -10;
        } else if (fn_801E0714() == 0) {
            result = 0x80000000;
        } else {
            *out = lbl_80537680.unknownC;
        }
        break;
    }

    if (result != 0) {
        thread = fn_801E0714();
        if (thread != 0) {
            thread->error = result;
        } else {
            lbl_805A11E4 = result;
        }
    }

    OSRestoreInterrupts(interrupts);
    return result;
}
