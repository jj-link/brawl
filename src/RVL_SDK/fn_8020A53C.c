#include <types.h>

#pragma force_active on

typedef struct {
    u32 unk0;
    s32 unk4;
    u8 pad8[0x1C];
    u32 unk24;
    u8 pad28[0xB8];
    u8 alarm[0x38];
} Entry;

extern Entry lbl_804ECE00[];

extern s32 fn_8020A438(s32, void **);
extern s32 fn_801E4978(s32, u32);
extern s32 fn_801E4C94(s32);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern void OSCancelAlarm(void *);

s32 fn_8020A53C(s32 arg0) {
    void *sp8;
    s32 interruptState;
    Entry *entry;
    s32 result;

    result = fn_8020A438(arg0, &sp8);
    if (result < 0) {
        return result;
    }

    entry = &lbl_804ECE00[arg0];
    interruptState = OSDisableInterrupts();

    if (entry->unk0 != 0) {
        fn_801E4978(arg0, 0);
        fn_801E4C94(arg0);
        OSCancelAlarm(entry->alarm);
        entry->unk0 = 0;
        entry->unk4 = -3;
        entry->unk24 = 0;
    }

    OSRestoreInterrupts(interruptState);
    return 0;
}
