#include <snd/snd_system.h>
#pragma force_active on

extern "C" s32 fn_2_2A0C8() {
    return g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
