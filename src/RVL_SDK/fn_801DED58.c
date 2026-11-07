#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern void fn_801E187C(OSThreadQueue *);

void fn_801DED58(OSThread *thread) {
    OSMutex *mutex;
    OSMutex *next;
    while ((mutex = thread->mutexQueue.head) != 0) {
        next = mutex->next;
        if (next == 0)
            thread->mutexQueue.tail = 0;
        else
            next->prev = 0;
        thread->mutexQueue.head = next;
        mutex->lock = 0;
        mutex->thread = 0;
        fn_801E187C(&mutex->queue);
    }
}