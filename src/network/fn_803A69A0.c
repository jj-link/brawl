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
extern int fn_802123A8(char *, int);
extern int fn_80212588(int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern int fn_8038E640(void);
extern int fn_803A0DC4(void);
extern int fn_803A6C78(int, int, int);
extern char lbl_804924D8[];

int fn_803A69A0(int arg0, int *arg1, int *arg2)
{
    int result = 0;
    int interrupts;
    int rc;
    OSThread *thread;

    interrupts = OSDisableInterrupts();
    switch ((int)lbl_805A11E0) {
    case 0:
        result = -39;
        break;
    default:
        if (lbl_80537680.state > -2) {
            result = -10;
        } else if (fn_801E0714() == 0) {
            result = 0x80000000;
        } else {
            lbl_80537680.state = -1;
            OSRestoreInterrupts(interrupts);
            rc = fn_802123A8(lbl_804924D8, 0);
            lbl_80537680.unknownC = rc;
            if (rc < 0) {
                interrupts = OSDisableInterrupts();
                if (lbl_80537680.unknownC == -6) {
                    result = -26;
                    lbl_80537680.state = -2;
                } else {
                    result = 0x80000000;
                }
            } else {
                *arg1 = rc;
                rc = fn_803A0DC4();
                if (rc == 0) {
                    rc = fn_8038E640();
                    if (rc < 0) {
                        if (rc == -8)
                            goto socket_minus8;
                        if (rc < -8)
                            goto generic_error;
                        if (rc >= -2)
                            goto socket_high;
                        goto generic_error;
                    }
                    switch (rc) {
                    case 3:
                    case 4:
                    case 5:
                        goto socket_connect;
                    default:
                        goto generic_error;
                    }
socket_connect:
                    result = fn_80212D40(lbl_80537680.unknownC, 0x1F, 0, 0, 0, 0);
                    if (result == 0)
                        *arg2 = 1;
                    else
                        result = fn_803A6C78(arg0, result, 1);
                    goto status_done;
socket_minus8:
                    result = fn_803A6C78(arg0, -26, 1);
                    goto status_done;
socket_high:
                    result = fn_803A6C78(arg0, 0x80000000, 1);
                    goto status_done;
generic_error:
                    result = fn_803A6C78(arg0, -48, 1);
status_done:
                    interrupts = OSDisableInterrupts();
                } else {
                    switch (rc) {
                    case -29: result = -26; break;
                    case -2: result = -39; break;
                    case -15: result = -48; break;
                    case -27: result = 0x80000000;
                    case -1: result = 0x80000000;
                    default: result = 0x80000000; break;
                    }
                    if (fn_80212588(lbl_80537680.unknownC) < 0)
                        result = 0x80000000;
                    interrupts = OSDisableInterrupts();
                    if (result != 0x80000000) {
                        lbl_80537680.unknownC = -1;
                        lbl_80537680.state = -2;
                    }
                }
            }
        }
        break;
    case 2:
        if (lbl_80537680.state < 0) {
            result = -10;
        } else if (fn_801E0714() == 0) {
            result = 0x80000000;
        } else {
            *arg2 = 0;
            *arg1 = lbl_80537680.unknownC;
        }
        break;
    }

    if (result != 0) {
        thread = fn_801E0714();
        if (thread != 0)
            thread->error = result;
        else
            lbl_805A11E4 = result;
    }
    OSRestoreInterrupts(interrupts);
    return result;
}
