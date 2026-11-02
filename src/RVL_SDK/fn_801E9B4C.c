#include <revolution/VI/vihardware.h>
#pragma force_active on

typedef struct { u8 pad[0x18]; u16 unk18; u16 unk1A; } FnThing;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 level);
extern FnThing *lbl_805A0814;

u32 fn_801E9B4C(void) {
    s32 level;
    u32 dph, old, dpv;
    u32 var_r31;
    FnThing *temp_r30;

    temp_r30 = lbl_805A0814;
    level = OSDisableInterrupts();
    dpv = VI_HW_REGS[VI_DPV] & 0x7FF;
    do {
        old = dpv;
        dph = VI_HW_REGS[VI_DPH] & 0x7FF;
        dpv = VI_HW_REGS[VI_DPV] & 0x7FF;
    } while (old != dpv);
    var_r31 = (dpv - 1) * 2 + (dph - 1) / lbl_805A0814->unk1A;
    OSRestoreInterrupts(level);
    if (var_r31 >= temp_r30->unk18)
        var_r31 -= temp_r30->unk18;
    return var_r31 >> 1;
}
