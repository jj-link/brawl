#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern "C" void fn_800F49E0(void* self) {
    *(int*)((char*)self + 0x64) = 0;
    g_sndSystem->playSE((SndID)0x27, -1, 0, 0, -1);
    (*(MuMsg**)((char*)self + 0x8c))->printIndex(3, 0x4c, 0);
}
