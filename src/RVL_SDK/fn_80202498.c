#include <revolution/AX/AXVPB.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
void fn_80202498(AXVPB* vpb, float ratio)
{
    BOOL enabled = OSDisableInterrupts();
    u32 value = (u32)(65536.0f * ratio);
    vpb->pb.src.ratioLo = value;
    vpb->pb.src.ratioHi = value >> 16;
    vpb->sync |= AX_PBSYNC_SRC_RATIO;
    OSRestoreInterrupts(enabled);
}
