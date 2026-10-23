#include <types.h>
#pragma force_active on

void GXInitTlutRegion(u32 *arg0, u32 arg1, u32 arg2) {
    u32 cmd;
    cmd = __rlwimi(0, arg1 - 0x80000, 23, 22, 31);
    cmd = __rlwimi(cmd, arg2, 10, 11, 21);
    cmd = __rlwimi(cmd, 0x65, 24, 0, 7);
    *arg0 = cmd;
}
