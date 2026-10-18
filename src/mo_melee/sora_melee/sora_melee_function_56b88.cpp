#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_800777DC(sndSystem*);

extern "C" void fn_27_56B88() {
    fn_800777DC(g_sndSystem);
}
