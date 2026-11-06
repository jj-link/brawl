#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

struct Entry {
    int unk0;
    unsigned char pad4[0x2C - 4];
    void (*unk2C)(int, int);
    unsigned char pad30[0x41 - 0x30];
    unsigned char unk41;
};

extern char lbl_80532248[];
extern struct Entry *lbl_80532308[];
extern int fn_8021AE80(int);
extern void fn_8021AEC4(int, int, void *);
extern void fn_801D6E14(OSAlarm *, int);
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);
extern void fn_8027A3F8(OSAlarm *, OSContext *);

void fn_8027A2E8(int arg0, int arg1) {
    switch (arg1) {
    case 0xFF: {
        struct Entry *ent = lbl_80532308[arg0];
        int id = ent->unk0;
        if (fn_8021AE80(id) != 0) {
            OSAlarm *alarm;
            fn_8021AEC4(id, 2, 0);
            alarm = (OSAlarm *)(lbl_80532248 + id * 0x30);
            fn_801D6E14(alarm, id);
            OSCancelAlarm(alarm);
            fn_801D68F8(alarm, (OS_BUS_CLOCK_SPEED / 4 / 1000) * 1000, fn_8027A3F8);
            ent->unk41 = 1;
        }
        break;
    }
    }
    {
        struct Entry *ent2 = lbl_80532308[arg0];
        void (*cb)(int, int) = ent2->unk2C;
        if (cb != 0) {
            cb(arg0, arg1);
        }
    }
}
