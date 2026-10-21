#include <snd/snd_system.h>
#pragma force_active on

extern "C" int fn_80074ECC(sndSystem* snd, int id, float f1, float f2) {
    if (*(unsigned char*)((char*)snd + 0x6EF) == 0) return -1;
    return snd->playSE(static_cast<SndID>(id), -1, 0, 0, -1);
}
