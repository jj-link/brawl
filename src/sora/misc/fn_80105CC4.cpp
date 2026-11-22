#pragma force_active on
#include <snd/snd_system.h>
#include <mu/mu_msg.h>

extern "C" void fn_8010535C(void*, void*);
extern const int lbl_805A27D0;

extern "C" void fn_80105CC4(char* arg0) {
    char* self = arg0;
    int cur = *(int*)(self + 0x2C);
    int flags = *(int*)(self + 0x44);
    int v = cur;
    if (flags & 2) {
        v = cur + 1;
        if (v >= 2) v = 0;
    }
    if (flags & 1) {
        v -= 1;
        if (v < 0) v = 1;
    }
    if (v != cur) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        *(int*)(self + 0x2C) = v;
        (*(MuMsg**)(self + 0xC))->printIndex(5, ((const int*)&lbl_805A27D0)[v], 0);
        fn_8010535C(arg0, *(int*)(arg0 + 0x2C) == 0 ? (void*)0 : (void*)2);
    }
}
