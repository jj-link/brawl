#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

extern void OSCreateAlarm(void *);
extern u64 OSGetTime(void);
extern void OSSetPeriodicAlarm(void *, u64, u64, void (*)(void *));
extern void fn_8027AD1C(void *);

void fn_8027B108(unsigned char *p)
{
    u64 t;
    u32 temp, period;

    if (p[0x1EC]) {
        OSCreateAlarm(p + 0x1A0);
        t = OSGetTime();
        temp = (*(u32 *)0x800000F8 >> 2) / 125000u;
        period = (temp * 0x65B9ABu) / 8000u;
        OSSetPeriodicAlarm(p + 0x1A0, t, (u64)period, fn_8027AD1C);
    }
}
