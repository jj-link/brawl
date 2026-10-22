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
extern void OSRestoreInterrupts(s32);
extern void fn_801DD320(u32);

s32 fn_801E4604(s32 chan, u32 buffer, u32 length, u32 mode, u32 callback) {
    Control* control = &lbl_804DE270[chan];
    s32 enabled = OSDisableInterrupts();
    if ((control->flags & 3) || !(control->flags & 4)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    control->callback = callback;
    if (callback != 0) {
        u32* regs = (u32*)(chan * 0x14);
        u32 base = 0xCD000000;
        regs = (u32*)(base + (u32)regs);
        regs[0x6800 / 4] = (regs[0x6800 / 4] & 0x7F5) | 8;
        fn_801DD320(0x200000U >> (chan * 3));
    }
    control->flags |= 1;
    {
        u32* regs = (u32*)(chan * 0x14);
        u32 base;
        u32 address = buffer & ~31U;
        base = 0xCD000000;
        regs = (u32*)(base + (u32)regs);
        regs[0x6804 / 4] = address;
        regs[0x6808 / 4] = length;
        regs[0x680C / 4] = (mode << 2) | 3;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}
