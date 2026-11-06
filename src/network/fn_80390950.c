#include <revolution/OS/OSMutex.h>
#pragma force_active on

void fn_80390950(OSMutex* mutex) {
    OSUnlockMutex(mutex);
}
