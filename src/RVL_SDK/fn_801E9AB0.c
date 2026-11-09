#include <revolution/VI/vihardware.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
typedef struct { u8 pad[0x18]; u16 unk18; u16 unk1A; } FnThing;
extern FnThing *lbl_805A0814;
extern u16 lbl_804DE640[];
extern int __cntlzw(unsigned int);
static inline u32 position(void) {
    u32 dph, old, dpv;
    dpv = VI_HW_REGS[VI_DPV] & 0x7FF;
    do {
        old = dpv;
        dph = VI_HW_REGS[VI_DPH] & 0x7FF;
        dpv = VI_HW_REGS[VI_DPV] & 0x7FF;
    } while (old != dpv);
    return (dpv - 1) * 2 + (dph - 1) / lbl_805A0814->unk1A;
}
s32 fn_801E9AB0(void) {
    s32 level;
    u32 res;
    u32 count;
    level = OSDisableInterrupts();
    count = position();
    res = count < lbl_805A0814->unk18;
    OSRestoreInterrupts(level);
    return (res ^ 1) ^ (lbl_804DE640[5] & 1);
}