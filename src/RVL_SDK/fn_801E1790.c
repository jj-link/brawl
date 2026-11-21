#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

#pragma optimization_level 1
#pragma peephole off

extern int lbl_805A06F4;
extern void fn_801E0A80(int);

void fn_801E1790(OSThreadQueue *queue)
{
    BOOL level;
    OSThread *thread;
    OSThread *iter;
    OSThread *prev;

    level = OSDisableInterrupts();
    thread = *(OSThread **)0x800000E4;
    thread->state = 4;
    thread->queue = queue;

    iter = queue->head;
    while (iter && iter->priority <= thread->priority)
        iter = iter->next;

    if (iter == 0) {
        prev = queue->tail;
        if (prev == 0)
            queue->head = thread;
        else
            prev->next = thread;

        thread->prev = prev;
        thread->next = 0;
        queue->tail = thread;
    } else {
        thread->next = iter;
        prev = iter->prev;
        iter->prev = thread;
        thread->prev = prev;

        if (prev == 0)
            queue->head = thread;
        else
            prev->next = thread;
    }

    lbl_805A06F4 = 1;
    if (lbl_805A06F4)
        fn_801E0A80(0);

    OSRestoreInterrupts(level);
}
