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
extern int lbl_805A11E4;
extern OSThread *fn_801E0714(void);
extern int fn_80212588(int);
extern int fn_803A0DD4(void);
int fn_803A6C78(int unused, int result, int mode)
{
    int interrupts;
    OSThread *thread;
    if (mode == 1) {
        switch (fn_803A0DD4()) {
        case 0: break;
        case -29: result = -26; break;
        case -1:
        default: result = 0x80000000; break;
        }
        if (fn_80212588(lbl_80537680.unknownC) < 0)
            result = 0x80000000;
        interrupts = OSDisableInterrupts();
        if (result != 0x80000000) {
            lbl_80537680.unknownC = -1;
            lbl_80537680.state = -2;
        }
    } else {
        interrupts = OSDisableInterrupts();
    }
    thread = fn_801E0714();
    if (thread != 0)
        thread->error = result;
    else
        lbl_805A11E4 = result;
    OSRestoreInterrupts(interrupts);
    return result;
}