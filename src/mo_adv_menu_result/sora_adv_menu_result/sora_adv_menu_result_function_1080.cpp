#pragma force_active on
#include <types.h>
#include <snd/snd_system.h>
extern "C" void fn_34_1080(void* arg0) {
    char* self = (char*)arg0;
    char* p = self;
    char* q = self + 0x1cc;
    char* prev = 0;
    for (int i = 0; i < 30; i++) {
        *(int*)(p + 0x1cc) = i + 1;
        *(char**)(p + 0x1e8) = prev;
        if (i < 29) *(char**)(p + 0x1e4) = self + ((i + 1) << 5) + 0x1cc;
        else *(char**)(p + 0x1e4) = 0;
        prev = q;
        p += 0x20;
        q += 0x20;
    }
    *(char**)(self + 0x58c) = self + 0x1cc;
    *(int*)(self + 0x590) = 0;
    *(s32*)(self + 0x5a0) = g_sndSystem->playSE((SndID)0x1ef8, -1, 0, 0, -1);
}