#include <types.h>
#pragma force_active on

extern const char lbl_80474F58[];
extern void OSReport(const char *msg, ...);
extern void OSDumpContext(const void *ctx);
extern void PPCHalt(void);

void fn_801E75D0(void) {
    void *ctx = (void *)(*(const u32 *)0xC0 + 0x80000000);
    OSReport(lbl_80474F58);
    OSDumpContext(ctx);
    PPCHalt();
}
