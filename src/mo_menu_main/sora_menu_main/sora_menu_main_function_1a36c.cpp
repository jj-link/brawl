#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_2_1A36C()
{
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
