#pragma force_active on
#pragma optimization_level 4
#pragma scheduling off
#pragma opt_unroll_loops on
#include <types.h>
#include <revolution/EXI/EXIBios.h>
#include <revolution/EXI/EXIHardware.h>
#include <revolution/OS/OSInterrupt.h>
extern EXIData lbl_804DE270[3];
extern void fn_801DD320(u32);
BOOL fn_801E42E4(EXIChannel chan, void *buf, s32 len, u32 type, EXICallback callback) {
    EXIData *exi = &lbl_804DE270[chan];
    BOOL enabled = OSDisableInterrupts();
    if ((exi->state & 3) || !(exi->state & 4)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->tcCallback = callback;
    if (callback != 0) {
        EXI_CHAN_PARAMS[chan].cpr = (EXI_CHAN_PARAMS[chan].cpr & 0x7F5) | 8;
        fn_801DD320(0x200000U >> (chan * 3));
    }
    exi->state |= 2;
    if (type != 0) {
        int i;
        u32 word = 0;
        for (i = 0; i < len; i++)
            word |= ((u8 *)buf)[i] << (3 - i) * 8;
        EXI_CHAN_PARAMS[chan].data = word;
    }
    exi->buffer = buf;
    exi->bytesRead = (type != 1) ? len : 0;
    EXI_CHAN_PARAMS[chan].cr = 1 | type << 2 | (len - 1) << 4;
    OSRestoreInterrupts(enabled);
    return 1;
}