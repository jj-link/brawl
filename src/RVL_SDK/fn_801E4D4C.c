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
    u32 unk18;
    unsigned char pad[0x24];
} Control;

extern Control lbl_804DE270[3];
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_801DD2A0(u32);
extern s32 fn_801E49FC(s32);

s32 fn_801E4D4C(s32 chan, u32 type, u32 arg2) {
    Control *control;
    s32 enabled;
    u32 val;
    u32 base;
    u32 off;
    u32 *regs;

    control = &lbl_804DE270[chan];
    enabled = OSDisableInterrupts();
    if (control->flags & 4) {
        goto fail;
    }
    if (chan == 2) {
        goto success;
    }
    if (type == 0 && !(control->flags & 8) && fn_801E49FC(chan) == 0) {
        goto fail;
    }
    if (!(control->flags & 0x10)) {
        goto fail;
    }
    if (control->unk18 == type) {
        goto success;
    }
fail:
    OSRestoreInterrupts(enabled);
    return 0;
success:
    control->flags |= 4;
    off = chan * 0x14;
    base = 0xCD000000;
    regs = (u32 *)(base + off);
    val = regs[0x6800 / 4];
    val = val & 0x405;
    val = val | (arg2 << 4);
    val = val | ((1 << type) << 7);
    regs[0x6800 / 4] = val;
    if (control->flags & 8) {
        switch (chan) {
        case 0:
            fn_801DD2A0(0x100000);
            break;
        case 1:
            fn_801DD2A0(0x20000);
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    return 1;
}
