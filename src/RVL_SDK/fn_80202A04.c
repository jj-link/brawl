#pragma force_active on
typedef unsigned int u32;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void fn_80203208(void *);

void fn_80202A04(void *arg0) {
    u32 temp;

    temp = OSDisableInterrupts();
    *(u32 *)((char *)arg0 + 0x10C) = *(u32 *)((char *)arg0 + 0x10C) | 1;
    fn_80203208(arg0);
    OSRestoreInterrupts(temp);
}
