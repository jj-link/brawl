#pragma force_active on
typedef signed long long s64;
typedef unsigned int u32;
typedef int s32;

struct OSAlarm;
typedef struct OSThread OSThread;
typedef struct OSContext OSContext;
typedef void (*OSAlarmHandler)(struct OSAlarm* alarm, OSContext* ctx);

typedef struct OSAlarm {
    OSAlarmHandler handler; // at 0x0
    u32 tag;                // at 0x4
    s64 end;                // at 0x8
    void* prev;             // at 0x10
    void* next;             // at 0x14
    s64 period;             // at 0x18
    s64 start;              // at 0x20
    void* userData;         // at 0x28
} OSAlarm;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void OSCreateAlarm(OSAlarm*);
extern void fn_801D6D80(OSAlarm*, u32);
extern void fn_801D6E14(OSAlarm*, OSThread*);
extern void fn_801D68F8(OSAlarm*, s64, OSAlarmHandler);
extern s32 OSSuspendThread(OSThread*);
extern void OSCancelAlarm(OSAlarm*);
extern void fn_801E1A5C(OSAlarm*, OSContext*);

void OSSleepTicks(s64 ticks) {
    OSThread* thread;
    s32 enabled;
    OSAlarm alarm;

    enabled = OSDisableInterrupts();

    thread = *(OSThread**)0x800000E4;
    if (thread == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }

    OSCreateAlarm(&alarm);
    fn_801D6D80(&alarm, (u32)thread);
    fn_801D6E14(&alarm, thread);
    fn_801D68F8(&alarm, ticks, fn_801E1A5C);

    OSSuspendThread(thread);
    OSCancelAlarm(&alarm);
    OSRestoreInterrupts(enabled);
}
