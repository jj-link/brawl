#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_80077DA0(sndSystem* p);

extern "C" void fn_27_56C3C() {
    fn_80077DA0(g_sndSystem);
}
