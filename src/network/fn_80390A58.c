#include <revolution/OS/OSMessage.h>
#pragma force_active on

void fn_80390A58(OSMessageQueue* queue) {
    OSSendMessage(queue, 0, 0);
}
