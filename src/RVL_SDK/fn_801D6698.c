#include <revolution/OS/OSAlarm.h>
#pragma force_active on

void OSCreateAlarm(OSAlarm* alarm) {
    alarm->handler = 0;
    alarm->tag = 0;
}
