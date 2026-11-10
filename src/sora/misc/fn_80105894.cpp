#include <types.h>
#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#pragma force_active on
extern const unsigned long lbl_80409250[];

extern "C" void fn_80105894(char* self) {
    int cur = *(int*)(self + 0x18);
    int flags = *(int*)(self + 0x44);
    int v = cur;
    if (flags & 2) {
        v = cur + 1;
        if (v >= 5) { v = 0; }
    }
    if (flags & 1) {
        v -= 1;
        if (v < 0) { v = 4; }
    }
    if (v != cur) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        *(int*)(self + 0x18) = v;
        (*(MuMsg**)(self + 0xc))->printIndex(0, lbl_80409250[v], 0);
        if (*(unsigned char*)(self + 0x30) != 0) {
            (*(MuMsg**)(self + 0xc))->printIndex(8, lbl_80409250[*(int*)(self + 0x18)], 0);
        }
    }
}
