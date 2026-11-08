#include <revolution/OS/OSMessage.h>
#pragma force_active on

extern void fn_801E0704(void* p);

void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* buffer, s32 capacity) {
    fn_801E0704(queue);
    fn_801E0704(&queue->recvQueue);
    queue->buffer = buffer;
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
}
