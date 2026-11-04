#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern unsigned char lbl_804DE640[0x58];
extern void fn_801E8C38(u16, u16, u8, u16, u16, u16, u16, u16, BOOL);

void fn_801E9A30(BOOL black)
{
    BOOL enabled;
    unsigned char *timing;

    enabled = OSDisableInterrupts();
    *(BOOL *)(lbl_804DE640 + 0x40) = black;
    timing = *(unsigned char **)(lbl_804DE640 + 0x54);
    fn_801E8C38(*(u16 *)(lbl_804DE640 + 0x0A),
                *(u16 *)(lbl_804DE640 + 0x06),
                timing[0],
                *(u16 *)(timing + 2),
                *(u16 *)(timing + 4),
                *(u16 *)(timing + 6),
                *(u16 *)(timing + 8),
                *(u16 *)(timing + 10),
                black);
    OSRestoreInterrupts(enabled);
}
