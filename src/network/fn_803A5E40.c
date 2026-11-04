#include <revolution/SO/SOBasic.h>
#include <revolution/OS/OS.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSThread.h>
#include <string.h>
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
extern const char *lbl_8059FE10;
extern int lbl_8059FE14;
extern unsigned char lbl_805A11E0;
extern int lbl_805A11E4;
extern int lbl_805A11E8;
extern OSThread *fn_801E0714(void);

int SOInit(SOInitInfo *info)
{
    int result = 0;
    BOOL interrupts;
    OSThread *thread;
    void *buffer;
    unsigned int masked;

    interrupts = OSDisableInterrupts();
    if (lbl_805A11E8 == 0) {
        OSRegisterVersion(lbl_8059FE10);
        lbl_805A11E8 = 1;
    }
    if ((int)lbl_805A11E0 != 0 && (int)lbl_805A11E0 >= 0 && (int)lbl_805A11E0 < 3) {
        result = -7;
    } else if (info == 0 || info->allocator == 0 || info->dealloc == 0) {
        result = -28;
    } else {
        memset(&lbl_80537680, 0, 0x18);
        lbl_80537680.alloc = info->allocator;
        lbl_80537680.free = (void (*)(int, void *, unsigned int))info->dealloc;
        lbl_80537680.count = 0;
        lbl_80537680.state = -2;
        lbl_80537680.fd = -1;
        if (lbl_80537680.alloc != 0) {
            buffer = lbl_80537680.alloc(11, 0x460);
            if (buffer != 0) {
                lbl_80537680.count++;
                if (lbl_8059FE14 != 0) {
                    masked = (unsigned int)buffer & 0x1fffffff;
                    if (masked < 0x10000000U || masked >= 0x18000000U) {
                        if (buffer != 0 && lbl_80537680.free != 0) {
                            lbl_80537680.count--;
                            lbl_80537680.free(11, buffer, 0x460);
                        }
                        buffer = 0;
                    }
                }
            }
        } else {
            buffer = 0;
        }
        lbl_80537680.buffer = buffer;
        if (buffer == 0) {
            result = -49;
        }
        if (buffer != 0) {
            lbl_805A11E0 = 1;
        }
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