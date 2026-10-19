#include <snd/snd_system.h>
#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern sndSystem* g_sndSystem;

void fn_34_F68(void* self) {
    u8 value = *(u8*)((char*)self + 0x5A4);
    if (value == 1)
        g_sndSystem->playBGM(0x282F, 0, true);
    else
        g_sndSystem->playBGM(0x2824, 0, true);
}
}
