#pragma force_active on
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSRtc.h>

typedef struct {
    u8 buf[0x40];
    u32 offset;
    BOOL enabled;
    BOOL locked;
    BOOL sync;
} SramCB;

extern SramCB lbl_804DD500;
extern s32 fn_801DFB80(s32, u32);

static void *LockSram(u32 offset) {
    BOOL enabled = OSDisableInterrupts();
    if (lbl_804DD500.locked != 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    lbl_804DD500.enabled = enabled;
    lbl_804DD500.locked = 1;
    return lbl_804DD500.buf + offset;
}

u16 fn_801DFF94(s32 pad) {
    OSSramEx *sram;
    u16 id;
    sram = (OSSramEx *)LockSram(0x14);
    id = sram->wirelessPadId[pad];
    fn_801DFB80(0, 0x14);
    return id;
}
