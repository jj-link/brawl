#include <types.h>
#include <gf/gf_gameframe_counter.h>
#pragma force_active on

class wnemSimple {
    unsigned char padding[0x221C];
    gfGameFrameCounter counters[2];

public:
    u32 getFrameCounter(s32 index);
};

u32 wnemSimple::getFrameCounter(s32 index) {
    if (index <= -1 || index >= 2) {
        return 0;
    }
    return counters[index].getCounter();
}