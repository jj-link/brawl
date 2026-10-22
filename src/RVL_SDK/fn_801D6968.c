#pragma force_active on
typedef unsigned long long u64;
typedef unsigned int u32;
typedef struct OSAlarm {
    u32 pad[6];
    u64 period;
    u64 start;
} OSAlarm;
int OSDisableInterrupts(void);
void OSRestoreInterrupts(int);
void fn_801D66A8(OSAlarm*, u32, u64, void*);
u64 fn_801E1BB8(u64);

void OSSetPeriodicAlarm(OSAlarm* alarm, u64 start, u64 period, void* handler) {
    int enabled = OSDisableInterrupts();
    alarm->period = period;
    alarm->start = fn_801E1BB8(start);
    fn_801D66A8(alarm, alarm->start, 0, handler);
    OSRestoreInterrupts(enabled);
}
