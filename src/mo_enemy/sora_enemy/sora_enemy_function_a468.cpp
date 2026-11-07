#include <gf/gf_gameframe_counter.h>
#pragma force_active on

extern "C" s32 fn_41_A468(s32 self, s32 index)
{
    if (index <= -1 || index >= 4) {
        return 0;
    }

    return ((gfGameFrameCounter*)(self + index * 0xC + 0x52E0))->getCounter();
}
