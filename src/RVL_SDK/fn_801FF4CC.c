#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void fn_801FF448(void *);
extern void fn_80201EF8(void *);
extern u32 lbl_804E4850[32];

void fn_801FF4CC(void *arg0) {
    u32 level;
    u32 head;

    level = OSDisableInterrupts();
    fn_801FF448(arg0);
    if (*(u16 *)((char *)arg0 + 0x38) == 1) {
        *(u32 *)((char *)arg0 + 0x20) = 1;
    }
    fn_80201EF8(arg0);
    head = lbl_804E4850[0];
    *(u32 *)arg0 = head;
    lbl_804E4850[0] = (u32)arg0;
    *(u32 *)((char *)arg0 + 0xC) = 0;
    OSRestoreInterrupts(level);
}
