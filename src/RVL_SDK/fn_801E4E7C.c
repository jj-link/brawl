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

extern Control lbl_804DE270[3];
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts();
extern void fn_801DD320(u32);
extern s32 fn_801E49FC(s32);

s32 fn_801E4E7C(s32 chan) {
    Control* control;
    u32 val;
    s32 enabled;
    u32* regs;
    u32 base;

    control = &lbl_804DE270[chan];
    enabled = OSDisableInterrupts();
    if (!(control->flags & 4)) {
        OSRestoreInterrupts();
        return 0;
    }
    control->flags &= ~4;
    regs = (u32*)(chan * 0x14);
    base = 0xCD000000;
    regs = (u32*)(base + (u32)regs);
    val = regs[0x6800 / 4];
    regs[0x6800 / 4] = val & 0x405;
    if (control->flags & 8) {
        switch (chan) {
            case 0: fn_801DD320(0x100000); break;
            case 1: fn_801DD320(0x20000); break;
        }
    }
    OSRestoreInterrupts(enabled);
    if (chan != 2 && (val & 0x80)) {
        return fn_801E49FC(chan) != 0;
    }
    return 1;
}
