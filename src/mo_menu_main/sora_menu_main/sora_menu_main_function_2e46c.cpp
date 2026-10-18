#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_2_2E46C() {
    g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
