#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_12_588(void*, int);

extern "C" void fn_12_97C(void* object) {
    fn_12_588(object, 0);
    g_sndSystem->playBGM(0x2863, 0, true);
}
