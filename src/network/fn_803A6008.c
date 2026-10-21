#pragma force_active on
typedef struct {
    int unknown0;
    void (*free)(int, void *, unsigned int);
    int state;
    int unknownC;
    void *buffer;
    int count;
} SOState;

typedef struct {
    unsigned char pad[0x30C];
    int error;
} SOThread;

extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern SOThread *fn_801E0714(void);
extern SOState lbl_80537680;
extern unsigned char lbl_805A11E0;
extern int lbl_805A11E4;

int SOFinish(void)
{
    int result = 0;
    int interrupts;
    SOThread *thread;

    interrupts = OSDisableInterrupts();
    switch ((int)lbl_805A11E0) {
    case 0:
        result = -7;
        break;
    case 1:
        if (lbl_80537680.state > -2) {
            result = -10;
        } else if (lbl_80537680.count > 1) {
            result = -6;
        } else {
            lbl_805A11E0 = 0;
            if (lbl_80537680.buffer != 0 && lbl_80537680.free != 0) {
                lbl_80537680.count--;
                lbl_80537680.free(11, lbl_80537680.buffer, 0x460);
            }
        }
        break;
    case 2:
        result = -26;
        break;
    }

    thread = fn_801E0714();
    if (thread != 0) {
        thread->error = result;
    } else {
        lbl_805A11E4 = result;
    }

    OSRestoreInterrupts(interrupts);
    return result;
}
