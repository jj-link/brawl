#include <revolution/types.h>
#pragma force_active on

extern void *fn_803CD2A8(void);
extern void OSCancelAlarm(void *alarm);
extern void fn_801D6E14(void *alarm, void *thread);
extern void fn_801D68F8(void *alarm, s64 tick, void *handler);

void fn_803D5340(void) {
    char *obj;
    u8 *p;
    u32 pos;
    u32 len;
    u32 count;
    u16 crc;
    u8 bits;

    obj = (char *)fn_803CD2A8();
    p = *(u8 **)(obj + 0x68);
    pos = *(u32 *)(obj + 0x6C);
    count = 0;
    crc = *(u16 *)(obj + 0x70);
    len = *(u32 *)(obj + 0x64);

    for (; pos < len; p++, pos++, count++) {
        s32 i;
        bits = *p;
        if (count >= 0x1400) {
            *(u8 **)(obj + 0x68) = p;
            *(u32 *)(obj + 0x6C) = pos;
            *(u16 *)(obj + 0x70) = crc;
            OSCancelAlarm(obj + 0x78);
            fn_801D6E14(obj + 0x78, obj + 0x60);
            fn_801D68F8(obj + 0x78, (s64)(((*(u32 *)0x800000F8 >> 2) / 1000) * 19), (void *)fn_803D5340);
            return;
        }
        for (i = 0; i < 8; i++) {
            if (crc & 0x8000) {
                crc <<= 1;
                crc ^= 0x1021;
            } else {
                crc <<= 1;
            }
            if (bits & 0x80) {
                crc ^= 1;
            }
            bits <<= 1;

        }
    }
    OSCancelAlarm(obj + 0x78);
    ((void (*)(u16))(*(u32 *)(obj + 0xA8)))(crc);
}
