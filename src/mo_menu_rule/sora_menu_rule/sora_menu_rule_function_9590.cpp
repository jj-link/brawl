#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_18_9590() {
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
