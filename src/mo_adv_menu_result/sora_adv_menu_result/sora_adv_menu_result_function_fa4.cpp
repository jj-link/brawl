#include <snd/snd_system.h>
#include <types.h>
#pragma force_active on

struct Unk {
    char _0[0x1BC];
    s32 unk1BC;
    char _1C0[0x3D8];
    s32 unk598;
};

extern "C" {

s32 fn_34_FA4(Unk* unk) {
    if (unk->unk598 == 120) {
        unk->unk1BC = 3;
    }
    if (unk->unk598 == 114) {
        g_sndSystem->playSE((SndID)0x2282, -1, 0, 0, -1);
    }
    unk->unk598 = unk->unk598 + 1;
    return unk->unk1BC;
}

}
