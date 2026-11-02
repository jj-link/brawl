#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

extern void fn_801D8218(OSContext*, void*, void*);
extern OSErrorHandler lbl_804DD190[OS_ERR_MAX];
extern u32 lbl_8059E9C0;

BOOL OSCreateThread(OSThread* thread, OSThreadFunc func, void* funcArg,
                    void* stackBegin, u32 stackSize, s32 prio, u16 flags)
{
    BOOL enabled;
    int i;
    OSThread* tail;
    void* sp;

    if (prio < 0 || prio > 31) {
        return 0;
    }

    thread->state = 1;
    thread->flags = flags & 1;
    thread->base = prio;
    thread->priority = prio;
    thread->suspend = 1;
    thread->val = 0xFFFFFFFF;
    thread->mutex = 0;
    thread->joinQueue.head = thread->joinQueue.tail = 0;
    thread->mutexQueue.head = thread->mutexQueue.tail = 0;

    sp = (void*)((u32)stackBegin & ~7);
    *((u32*)sp - 2) = 0;
    *((u32*)sp - 1) = 0;

    fn_801D8218(&thread->context, (void*)func, (char*)sp - 8);
    thread->context.lr = (u32)OSExitThread;
    thread->context.gprs[3] = (u32)funcArg;

    thread->stackBegin = (u32*)stackBegin;
    thread->stackEnd = (u32*)((char*)stackBegin - stackSize);
    *thread->stackEnd = 0xDEADBABE;

    thread->error = 0;
    for (i = 0; i < 2; i++) {
        thread->specific[i] = 0;
    }

    enabled = OSDisableInterrupts();
    if (lbl_804DD190[OS_ERR_FP_EXCEPTION] != 0) {
        thread->context.srr1 |= 0x900;
        thread->context.state |= 1;
        thread->context.fpscr = lbl_8059E9C0 & 0xF8;
        thread->context.fpscr |= 4;

        for (i = 0; i < 32; i++) {
            *(u64*)&thread->context.fprs[i] = 0xFFFFFFFFFFFFFFFF;
            *(u64*)&thread->context.psfs[i] = 0xFFFFFFFFFFFFFFFF;
        }
    }

    tail = ((OSThreadQueue*)0x800000DC)->tail;
    if (tail == 0) {
        ((OSThreadQueue*)0x800000DC)->head = thread;
    } else {
        tail->nextActive = thread;
    }

    thread->prevActive = tail;
    thread->nextActive = 0;
    ((OSThreadQueue*)0x800000DC)->tail = thread;
    tail = thread;

    OSRestoreInterrupts(enabled);
    return 1;
}
