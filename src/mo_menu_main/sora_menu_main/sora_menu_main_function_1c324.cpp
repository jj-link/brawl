#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_2_1C324() {
    g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
