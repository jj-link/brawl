#pragma force_active on
#pragma optimization_level 1
#pragma scheduling off

#include <revolution/EXI/EXIBios.h>
#include <revolution/OS/OSInterrupt.h>

extern EXIData lbl_804DE270[3];
extern void fn_801E41F4(EXIChannel, EXIData*);
extern void* fn_803F602C(void*, const void*, u32);

BOOL fn_801E55DC(EXIChannel chan) {
    EXIData* exi = &lbl_804DE270[chan];
    BOOL enabled;
    EXICallback callback;
    s32 count;

    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x10)) {
        ((BOOL (*)())OSRestoreInterrupts)();
        return FALSE;
    }
    exi->state &= ~0x10;
    fn_801E41F4(chan, exi);
    count = exi->numItems;
    if (count > 0) {
        callback = exi->items[0].callback;
        if ((exi->numItems = count - 1) > 0) {
            fn_803F602C(&exi->items[0], &exi->items[1], exi->numItems * sizeof(EXIItem));
        }
        callback(chan, NULL);
    }
    OSRestoreInterrupts(enabled);
    return TRUE;
}
