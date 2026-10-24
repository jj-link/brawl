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
    unsigned char pad[0x30];
} Control;
extern char lbl_804DE270[];
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_801E41F4(s32, Control*);

s32 fn_801E4978(s32 chan, u32 callback) {
    s32 off = chan << 6;
    Control* base = (Control*)lbl_804DE270;
    Control* control = (Control*)((char*)base + off);
    u32 old;
    s32 enabled = OSDisableInterrupts();
    old = control->unk0;
    control->unk0 = callback;
    if (chan != 2) {
        fn_801E41F4(chan, control);
    } else {
        fn_801E41F4(0, base);
    }
    OSRestoreInterrupts(enabled);
    return old;
}
