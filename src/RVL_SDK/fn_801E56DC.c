#include <revolution/EXI/EXIBios.h>
#include <revolution/EXI/EXIHardware.h>
#include <revolution/OS/OSHardware.h>
#include <revolution/OS/OSInterrupt.h>
#pragma scheduling off
#pragma force_active on

extern EXIData lbl_804DE270[3];
extern u32 lbl_805A0768;
extern BOOL fn_801E49FC(EXIChannel);
extern void fn_801DD320(u32);
extern void fn_801DD2A0(u32);
extern void fn_801E41F4(EXIChannel, EXIData*);
extern BOOL fn_801E54E0(EXIChannel, u32, EXICallback);
extern BOOL fn_801E4D4C(EXIChannel, u32, u32);
extern BOOL fn_801E42E4(EXIChannel, void*, s32, u32, EXICallback);
extern BOOL fn_801E46FC(EXIChannel);
extern BOOL fn_801E4E7C(EXIChannel);
extern void fn_801E56B4(EXIChannel, OSContext*);
extern void* fn_803F602C(void*, const void*, u32);

static inline BOOL attach(EXIChannel chan, EXICallback callback) {
    EXIData* exi = &lbl_804DE270[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & 8) || !fn_801E49FC(chan)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    EXI_CHAN_PARAMS[chan].cpr = (EXI_CHAN_PARAMS[chan].cpr & 0x7f5) | 2;
    exi->extCallback = callback;
    fn_801DD320(0x100000U >> (chan * 3));
    exi->state |= 8;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

static inline BOOL unlock(EXIChannel chan) {
    EXIData* exi = &lbl_804DE270[chan];
    BOOL enabled;
    EXICallback callback;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x10)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    exi->state &= ~0x10;
    fn_801E41F4(chan, exi);
    if (exi->numItems > 0) {
        callback = exi->items[0].callback;
        if (--exi->numItems > 0) {
            fn_803F602C(&exi->items[0], &exi->items[1], exi->numItems * sizeof(EXIItem));
        }
        callback(chan, NULL);
    }
    OSRestoreInterrupts(enabled);
    return TRUE;
}

static inline BOOL detach(EXIChannel chan) {
    EXIData* exi = &lbl_804DE270[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 8)) {
        OSRestoreInterrupts(enabled);
        return TRUE;
    }
    if ((exi->state & 0x10) && exi->dev == 0) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    exi->state &= ~8;
    fn_801DD2A0(0x500000U >> (chan * 3));
    OSRestoreInterrupts(enabled);
    return TRUE;
}

s32 fn_801E56DC(EXIChannel chan, u32 dev, u32* out) {
    EXIData* exi = &lbl_804DE270[chan];
    u32 imm;
    s32 ret;
    s32 time;
    BOOL enabled;
    if (chan == 0 && dev == 2 && lbl_805A0768 != 0) {
        *out = lbl_805A0768;
        return 1;
    }
    if (chan < 2 && dev == 0) {
        if (!fn_801E49FC(chan)) return 0;
        if (exi->lastInsert == OS_EXI_LAST_INSERT[chan]) {
            *out = exi->id;
            return exi->lastInsert;
        }
        if (!attach(chan, NULL)) return 0;
        time = OS_EXI_LAST_INSERT[chan];
    }
    enabled = OSDisableInterrupts();
    ret = !fn_801E54E0(chan, dev, (chan < 2 && dev == 0) ? fn_801E56B4 : NULL);
    if (ret == 0) {
        ret = !fn_801E4D4C(chan, dev, 0);
        if (ret == 0) {
            imm = 0;
            ret |= !fn_801E42E4(chan, &imm, 2, 1, NULL);
            ret |= !fn_801E46FC(chan);
            ret |= !fn_801E42E4(chan, out, 4, 0, NULL);
            ret |= !fn_801E46FC(chan);
            ret |= !fn_801E4E7C(chan);
        }
        unlock(chan);
    }
    OSRestoreInterrupts(enabled);
    if (chan < 2 && dev == 0) {
        detach(chan);
        enabled = OSDisableInterrupts();
        ret |= time != OS_EXI_LAST_INSERT[chan];
        if (ret == 0) {
            exi->id = *out;
            exi->lastInsert = time;
        }
        OSRestoreInterrupts(enabled);
        return ret != 0 ? 0 : exi->lastInsert;
    }
    return ret == 0;
}
