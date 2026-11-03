#include <revolution/EXI/EXIBios.h>
#include <revolution/EXI/EXIHardware.h>
#include <revolution/OS/OSTime.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
#pragma optimization_level 2
#pragma scheduling off
extern EXIData lbl_804DE270[3];
extern s64 fn_803F1470(s64, s64);
BOOL fn_801E49FC(EXIChannel chan) {
    EXIData* exi = (EXIData*)((u32)lbl_804DE270 + ((u32)chan << 6));
    BOOL enabled;
    BOOL ret;
    u32 cpr;
    EXIChannelParam* regs;
    if (chan == EXI_CHAN_2) return TRUE;
    ret = TRUE;
    enabled = OSDisableInterrupts();
    regs = (EXIChannelParam*)(0xCD000000 + chan * 0x14);
    cpr = EXI_CHAN_PARAMS[chan].cpr;
    if (!(exi->state & EXI_STATE_ATTACHED)) {
        if (cpr & EXI_CPR_EXTINT) {
            EXI_CHAN_PARAMS[chan].cpr = (EXI_CHAN_PARAMS[chan].cpr & 0x7f5) | 0x800;
            OS_EXI_LAST_INSERT[chan] = exi->lastInsert = 0;
        }
        if (cpr & EXI_CPR_EXT) {
            s32 time = (s32)fn_803F1470(fn_803F1470(OSGetTime(), OS_TIME_SPEED / 1000), 100) + 1;
            s32* last = (s32*)&OS_EXI_LAST_INSERT[chan];
            if (*last == 0) *last = time;
            if (time - *last < 3) ret = FALSE;
        } else {
            OS_EXI_LAST_INSERT[chan] = exi->lastInsert = 0;
            ret = FALSE;
        }
    } else if (!(cpr & EXI_CPR_EXT) || cpr & EXI_CPR_EXTINT) {
        OS_EXI_LAST_INSERT[chan] = exi->lastInsert = 0;
        ret = FALSE;
    }
    OSRestoreInterrupts(enabled);
    return ret;
}