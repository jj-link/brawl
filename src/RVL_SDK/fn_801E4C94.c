#pragma force_active on
#pragma optimization_level 1
#pragma scheduling off

typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    u32 callback;
    u32 unk8;
    u32 flags;
    u32 unk10;
    u32 unk14;
    s32 unk18;
    unsigned char pad[0x24];
} Control;

extern Control lbl_804DE270[3];
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts();
extern void fn_801DD2A0(u32);

s32 fn_801E4C94(s32 chan) {
    Control* control = &lbl_804DE270[chan];
    s32 enabled = OSDisableInterrupts();

    if (!(control->flags & 8)) {
        OSRestoreInterrupts();
        return 1;
    }

    if ((control->flags & 0x10) && control->unk18 == 0) {
        OSRestoreInterrupts();
        return 0;
    }

    control->flags &= ~8;
    fn_801DD2A0(0x500000U >> (chan * 3));
    OSRestoreInterrupts(enabled);
    return 1;
}
