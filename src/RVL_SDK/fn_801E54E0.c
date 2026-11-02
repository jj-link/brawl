#pragma opt_lifetimes off
#pragma scheduling off
#include <revolution/EXI/EXIBios.h>
#pragma force_active on
extern EXIData lbl_804DE270[3];
extern void fn_801E41F4(EXIChannel, EXIData*);

BOOL fn_801E54E0(EXIChannel chan, u32 dev, EXICallback callback)
{
    EXIData* exi;
    BOOL enabled;
    int i;
    
    exi = &lbl_804DE270[chan];
    enabled = OSDisableInterrupts();
    if (exi->state & EXI_STATE_LOCKED) {
        if (callback != NULL) {
            for (i = 0; i < exi->numItems; i++) {
                if (exi->items[i].dev == dev) {
                    OSRestoreInterrupts(enabled);
                    return FALSE;
                }
            }
            exi->items[exi->numItems].callback = callback;
            exi->items[exi->numItems].dev = dev;
            exi->numItems++;
        }
        OSRestoreInterrupts(enabled);
        return FALSE;
    } else {
        exi->state |= EXI_STATE_LOCKED;
        exi->dev = dev;
        fn_801E41F4(chan, exi);
        OSRestoreInterrupts(enabled);
        return TRUE;
    }
}