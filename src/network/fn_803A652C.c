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
extern int fn_80212588(int);
extern int fn_803A0DB4(int *);

static inline int convert(int rc, int out)
{
    int result = -28;
    switch (rc) {
    case 0: result = 0; break;
    case -22:
    case -13: result = -48; break;
    case -33:
    case -2: result = out; break;
    case -1: result = 0x80000000; break;
    case -29: result = -26; break;
    }
    return result;
}

int SOCleanup(void)
{
    int result;
    int interrupts;
    int out;
    int rc;
    OSThread *thread;

    interrupts = OSDisableInterrupts();
    out = 0;
    switch ((int)lbl_805A11E0) {
    default:
    case 0:
        result = -39;
        break;
    case 1:
        result = -7;
        break;
    case 2:
        if (lbl_80537680.state < 0) {
            result = -10;
        } else if (fn_801E0714() == 0) {
            result = 0x80000000;
        } else {
            lbl_80537680.state = -1;
            OSRestoreInterrupts(interrupts);
            rc = fn_803A0DB4(&out);
            result = convert(rc, out);
            if (result == 0) {
                if (fn_80212588(lbl_80537680.unknownC) < 0)
                    result = 0x80000000;
                else
                    lbl_80537680.unknownC = -1;
            }
            interrupts = OSDisableInterrupts();
            if (result == 0) {
                lbl_805A11E0 = 1;
                lbl_80537680.state = -2;
            } else if (result != 0x80000000) {
                lbl_805A11E0 = 2;
                lbl_80537680.state = 0;
            }
        }
        break;
    }
    thread = fn_801E0714();
    if (thread != 0)
        thread->error = result;
    else
        lbl_805A11E4 = result;
    OSRestoreInterrupts(interrupts);
    return result;
}