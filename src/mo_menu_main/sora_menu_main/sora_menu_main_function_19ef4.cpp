#include <snd/snd_system.h>
#pragma force_active on

extern "C" {
extern sndSystem* g_sndSystem;
}

extern "C" int fn_2_19EF4() {
    return g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
