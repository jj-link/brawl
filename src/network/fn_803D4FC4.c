#include <types.h>
#include <string.h>
#pragma force_active on

extern void fn_803D4E0C(void);

void fn_803D4FC4(void* arg0, void* arg1) {
    u8* p0 = (u8*)arg0;
    u8* p1 = (u8*)arg1;
    fn_803D4E0C();
    memcpy(p1 + 0x2E, p0 + 0x36, 0x14);
    *(s16*)(p1 + 0x42) = 0;
}
