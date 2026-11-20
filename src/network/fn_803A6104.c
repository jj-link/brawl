#include <revolution/SO/SOBasic.h>
#include <revolution/OS/OS.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

typedef struct {
    alloc_t alloc;
    void (*free)(int, void *, unsigned int);
    int state;
    int fd;
    void *buffer;
    int count;
} SOState;

extern SOState lbl_80537680;
extern char lbl_804924D8[];
extern unsigned char lbl_805A11E0;
extern int lbl_805A11E4;

extern s64 fn_801E1B54(void);
extern OSThread *fn_801E0714(void);
extern int fn_8038E640(void);
extern int fn_802123A8(void *, int);
extern int fn_80212588(int);
extern int fn_803A0DA4(int *);
extern int fn_803A6D5C(u32);
extern u64 fn_803F1470(s64, s64);

static inline int convert_error(int st, int error)
{
    int result = -0x1C;
    switch (st) {
    case 0: result = 0; break;
    case -22:
    case -13: result = -0x30; break;
    case -33:
    case -2: result = error; break;
    case -1: result = (int)0x80000000; break;
    case -29: result = -0x1A; break;
    }
    return result;
}

static inline s64 remaining_time(s64 deadline)
{
    if (deadline != 0) {
        return deadline - fn_801E1B54();
    }
    return 0;
}

int SOStartupEx(u32 arg0)
{
    int result;
    s64 deadline = 0;
    s64 now;
    s64 rem;
    int retries;
    int sp8;
    int st;
    int fdv;
    BOOL intr;
    OSThread *thread;
    u32 prod;

    if (arg0 != 0) {
        now = fn_801E1B54();
        prod = arg0 * ((*(u32 *)0x800000F8 / 4) / 1000);
        deadline = prod + now;
    }

    retries = 4;
outer:
    intr = OSDisableInterrupts();
    switch ((int)lbl_805A11E0) {
    case 0:
    default:
        result = -0x27;
        goto store;
    case 2:
        result = -7;
        goto store;
    case 1:
        if (lbl_80537680.state > -2) {
            result = -0xA;
            goto store;
        }
        thread = fn_801E0714();
        if (thread == NULL) {
            result = (int)0x80000000;
            goto store;
        }
        lbl_80537680.state = -1;
        OSRestoreInterrupts(intr);
loop1:
        st = fn_8038E640();
        if (st == -8 || st == 1) {
            OSSleepTicks(100 * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
            if (deadline != 0) {
                now = fn_801E1B54();
                if (deadline >= now) {
                    goto loop1;
                }
                if (st == 1) {
                    result = -0x79;
                    goto finish;
                } else {
                    result = (int)0x80000000;
                    goto finish;
                }
            }
            goto loop1;
        }
        if (st < 0) {
            result = (int)0x80000000;
            goto finish;
        }
        if (st == 2) {
            result = -0x2D;
            goto finish;
        }
loop2:
        fdv = fn_802123A8(lbl_804924D8, 0);
        lbl_80537680.fd = fdv;
        if (fdv == -6) {
            OSSleepTicks(100 * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
            if (deadline != 0) {
                now = fn_801E1B54();
                if (deadline >= now) {
                    goto loop2;
                }
                result = (int)0x80000000;
                goto finish;
            }
            goto loop2;
        }
        if (fdv < 0) {
            result = (int)0x80000000;
            goto finish;
        }
        result = 0;
        sp8 = 0;
loop3:
        st = fn_803A0DA4(&sp8);
        if (st == -0x1D) {
            OSSleepTicks(100 * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
            if (deadline != 0) {
                now = fn_801E1B54();
                if (deadline >= now) {
                    goto loop3;
                }
                result = (int)0x80000000;
            } else {
                goto loop3;
            }
        }
        if (result == 0) {
            result = convert_error(st, sp8);
        }
        if (result != 0) {
            if (fn_80212588(lbl_80537680.fd) < 0) {
                result = (int)0x80000000;
            } else {
                lbl_80537680.fd = -1;
            }
        }
        break;
    }

finish:
    intr = OSDisableInterrupts();
    if (result == 0) {
        lbl_805A11E0 = 2;
        lbl_80537680.state = 0;
    } else {
        lbl_805A11E0 = 1;
        if (result != (int)0x80000000) {
            lbl_80537680.state = -2;
        }
    }

store:
    thread = fn_801E0714();
    if (thread != NULL) {
        thread->error = result;
    } else {
        lbl_805A11E4 = result;
    }
    OSRestoreInterrupts(intr);
    if (result == 0) {
        rem = remaining_time(deadline);
        if (deadline != 0 && rem <= 0) {
            result = -0x4C;
        } else {
            result = fn_803A6D5C((u32)fn_803F1470(rem, (s64)((*(u32 *)0x800000F8 / 4) / 1000)));
        }
        if (result != 0) {
            SOCleanup();
        }
    }
    thread = fn_801E0714();
    if (thread != NULL) {
        thread->error = result;
    } else {
        lbl_805A11E4 = result;
    }
    if (result == -0x70) {
        retries--;
        if (retries >= 0) {
            goto outer;
        }
    }
    return result;
}
