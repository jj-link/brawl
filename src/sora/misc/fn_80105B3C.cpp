#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#pragma force_active on
extern const unsigned long lbl_80409268[];
extern "C" void fn_80105B3C(char* self) {
    int flags = *(int*)(self + 0x44);
    int cur = *(int*)(self + 0x24);
    int v = cur;
    if (flags & 2) {
        v = cur + 1;
        if (v >= 6) { v = 0; }
    }
    if (flags & 1) {
        v -= 1;
        if (v < 0) { v = 5; }
    }
    if (v != cur) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        *(int*)(self + 0x24) = v;
        (*(MuMsg**)(self + 0xc))->printIndex(3, lbl_80409268[v], 0);
        if (*(unsigned char*)(self + 0x30)) {
            (*(MuMsg**)(self + 0xc))->printIndex(9, lbl_80409268[*(int*)(self + 0x24)], 0);
        }
    }
}