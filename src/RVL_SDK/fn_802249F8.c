#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Entry {
    unsigned int active;
    unsigned int address;
    unsigned short remaining;
    unsigned short pad;
    unsigned int offset;
    void (*callback)(int, int);
} Entry;
extern Entry lbl_804F9F70[];
void fn_802249F8(int, int);
extern void fn_802252E8(int, unsigned int, unsigned short, unsigned int, void (*)(int, int));

void fn_802249F8(int idx, int result)
{
    unsigned short count;
    void (*callback)(int, int);
    BOOL enabled;
    if (lbl_804F9F70[idx].remaining == 0) {
        lbl_804F9F70[idx].active = 0;
        callback = lbl_804F9F70[idx].callback;
        lbl_804F9F70[idx].callback = 0;
        if (callback)
            callback(idx, result);
    } else {
        count = lbl_804F9F70[idx].remaining > 16 ? 16 : lbl_804F9F70[idx].remaining;
        if (result == 0) {
            lbl_804F9F70[idx].remaining -= count;
            lbl_804F9F70[idx].offset += 16;
            lbl_804F9F70[idx].address += 16;
            enabled = OSDisableInterrupts();
            fn_802252E8(idx, lbl_804F9F70[idx].address, count, lbl_804F9F70[idx].offset, fn_802249F8);
            OSRestoreInterrupts(enabled);
        } else if (result == -2) {
            enabled = OSDisableInterrupts();
            fn_802252E8(idx, lbl_804F9F70[idx].address, count, lbl_804F9F70[idx].offset, fn_802249F8);
            OSRestoreInterrupts(enabled);
        } else {
            lbl_804F9F70[idx].active = 0;
            callback = lbl_804F9F70[idx].callback;
            lbl_804F9F70[idx].callback = 0;
            if (callback)
                callback(idx, result);
        }
    }
}