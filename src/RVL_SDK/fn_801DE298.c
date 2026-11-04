#include <revolution/OS/OSMessage.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern void fn_801E1790(OSThreadQueue *);
extern void fn_801E187C(OSThreadQueue *);

BOOL fn_801DE298(OSMessageQueue *queue, OSMessage mesg, u32 flags)
{
    s32 lastMesg;
    BOOL enabled = OSDisableInterrupts();

    while (queue->capacity <= queue->size) {
        if (!(flags & OS_MSG_BLOCKING)) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }
        fn_801E1790(&queue->sendQueue);
    }

    lastMesg = (queue->front + queue->capacity - 1) % queue->capacity;
    queue->front = lastMesg;
    queue->buffer[lastMesg] = mesg;
    queue->size++;
    fn_801E187C(&queue->recvQueue);
    OSRestoreInterrupts(enabled);
    return TRUE;
}