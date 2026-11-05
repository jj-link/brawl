#include <revolution/OS/OSMessage.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern void fn_801E1790(OSThreadQueue *);
extern void fn_801E187C(OSThreadQueue *);

BOOL OSReceiveMessage(OSMessageQueue *queue, OSMessage *mesg, u32 flags) {
    BOOL enabled = OSDisableInterrupts();

    while (queue->size == 0) {
        if (!(flags & OS_MSG_BLOCKING)) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }
        fn_801E1790(&queue->recvQueue);
    }

    if (mesg != NULL) {
        *mesg = queue->buffer[queue->front];
    }
    {
        s32 cap = queue->capacity;
        s32 next = queue->front + 1;
        s32 q = next / cap;
        queue->front = next - q * cap;
        queue->size--;
    }
    fn_801E187C(&queue->sendQueue);
    OSRestoreInterrupts(enabled);
    return TRUE;
}