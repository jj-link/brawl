#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

struct Obj {
    int unk00;
    unsigned char pad04[0x24 - 4];
    char *unk24;
    unsigned char pad28[0x34 - 0x28];
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned char pad40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
};

extern char lbl_80532248[];
extern int fn_8027B4A8(char *base, int idx);
extern int fn_8021AE80(int);
extern void fn_8021AEC4(int, int, void *);
extern void fn_801D6E14(OSAlarm *, int);
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);
extern unsigned char fn_80218D6C(int);
extern void fn_8027A3F8(OSAlarm *, OSContext *);

void fn_8027A95C(struct Obj *obj) {
    int idx = obj->unk00;
    if (fn_8027B4A8(obj->unk24, idx) == 0) {
        if (obj->unk42 != 0) {
            if (obj->unk43 == 0) {
                u64 t = OSGetTime();
                obj->unk3C = (u32)t;
                obj->unk38 = (u32)(t >> 32);
                obj->unk43 = 1;
                return;
            }
            if (((u32)OSGetTime() - obj->unk3C) / (OS_BUS_CLOCK_SPEED / 4 / 1000) >= 1000) {
                obj->unk42 = 0;
                obj->unk43 = 0;
            }
        }
    } else {
        if (obj->unk42 != 0) {
            obj->unk43 = 0;
            if (((u32)OSGetTime() - obj->unk34) / (OS_BUS_CLOCK_SPEED / 4 / 1000) >= 0x75300) {
                idx = obj->unk00;
                obj->unk42 = 0;
                obj->unk43 = 0;
                if (fn_8021AE80(idx) != 0) {
                    OSAlarm *alarm;
                    fn_8021AEC4(idx, 2, 0);
                    alarm = (OSAlarm *)(lbl_80532248 + idx * 0x30);
                    fn_801D6E14(alarm, idx);
                    OSCancelAlarm(alarm);
                    fn_801D68F8(alarm, (OS_BUS_CLOCK_SPEED / 4 / 1000) * 1000, fn_8027A3F8);
                    obj->unk41 = 1;
                }
                return;
            }
        }
        if (obj->unk41 == 0 && fn_80218D6C(idx) <= 0x55) {
            int idx2 = obj->unk00;
            if (fn_8021AE80(idx2) != 0) {
                OSAlarm *alarm;
                fn_8021AEC4(idx2, 2, 0);
                alarm = (OSAlarm *)(lbl_80532248 + idx2 * 0x30);
                fn_801D6E14(alarm, idx2);
                OSCancelAlarm(alarm);
                fn_801D68F8(alarm, (OS_BUS_CLOCK_SPEED / 4 / 1000) * 1000, fn_8027A3F8);
                obj->unk41 = 1;
            }
        }
    }
}
