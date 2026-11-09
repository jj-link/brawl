#include <types.h>
#include <revolution/GX.h>
#pragma force_active on
void fn_801F52B0(u16 index, u32 id) {
    GX_FIFO_LOAD_INDX_B(id * 3 + GX_XF_MEM_NRMMTX, 3 * 3 - 1, index);
}
