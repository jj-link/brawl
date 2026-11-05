#include <types.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern void fn_8018B05C(void*);
extern OSMutex lbl_80532170;

typedef struct {
    char _00[0x418];
    char alarms[0x30 * 8]; // 0x418
    char _5D0[0x5D0 - 0x598];
    char tail[0x18]; // 0x5d0
} Obj;

Obj* fn_8026F9D0(Obj* obj, s32 arg1) {
    s32 off;
    s32 i;

    *(s32*)((char*)obj + 0x4) = arg1;
    *(s32*)((char*)obj + 0x1E8) = 0;
    *(s32*)((char*)obj + 0x200) = 0;
    fn_8018B05C((char*)obj + 0x208);
    *(s32*)((char*)obj + 0x404) = 0;
    i = 0;
    off = 0;
    *(s32*)((char*)obj + 0x408) = 0x1E;
    *(s32*)((char*)obj + 0x40C) = 0;
    *(u8*)((char*)obj + 0x410) = 0;
    *(u8*)((char*)obj + 0x411) = 0;
    *(u8*)((char*)obj + 0x412) = 0;
    *(s32*)((char*)obj + 0x10) = 2;
    *(s32*)((char*)obj + 0xB0) = -1;
    *(s32*)((char*)obj + 0x14) = -1;
    *(s32*)((char*)obj + 0x18) = 0;
    *(s32*)((char*)obj + 0x0) = 0;
    *(s32*)((char*)obj + 0x64) = 0;
    *(u8*)((char*)obj + 0x86) = 0;
    *(s32*)((char*)obj + 0x68) = 0;
    *(s32*)((char*)obj + 0x6C) = 0;
    *(s32*)((char*)obj + 0x70) = 0;
    *(s32*)((char*)obj + 0x74) = 0;
    *(u8*)((char*)obj + 0x87) = 0;
    *(u8*)((char*)obj + 0x88) = 0;

    do {
        OSCreateAlarm((OSAlarm*)&obj->alarms[off]);
        OSCreateAlarm((OSAlarm*)(&obj->alarms[off] + 0xC0));
        i += 1;
        off += 0x30;
    } while (i < 4);

    OSCreateAlarm((OSAlarm*)&obj->alarms[0x180]);
    OSInitMutex(&lbl_80532170);
    *(s32*)((char*)obj + 0x5D0) = 0;
    *(s32*)((char*)obj + 0x5D4) = 0;
    *(s32*)((char*)obj + 0x5D8) = 0;
    *(s32*)((char*)obj + 0x5DC) = 0;
    *(s32*)((char*)obj + 0x5E0) = 0;
    *(s32*)((char*)obj + 0x5E4) = 0;
    return obj;
}
