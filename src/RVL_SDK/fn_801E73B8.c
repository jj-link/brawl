#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
typedef void (*Callback)(int, unsigned int);
extern unsigned int fn_801E7204(int);
extern unsigned int lbl_80474EB0[];
extern Callback lbl_804DE510[][4];

unsigned int fn_801E73B8(int chan, Callback callback) {
    BOOL enabled = OSDisableInterrupts();
    unsigned int result = fn_801E7204(chan);
    if (lbl_80474EB0[chan] & 0x80) {
        int i;
        for (i = 0; i < 4; i++) {
            if (lbl_804DE510[chan][i] == callback) break;
            if (lbl_804DE510[chan][i] == 0) {
                lbl_804DE510[chan][i] = callback;
                break;
            }
        }
    } else {
        callback(chan, result);
    }
    OSRestoreInterrupts(enabled);
    return result;
}