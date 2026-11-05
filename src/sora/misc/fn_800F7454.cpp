#include <gf/gf_model.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" double fn_800F5344(void);
extern "C" float getFrame__16gfModelAnimationFd(gfModelAnimation*, double);

struct Inner {
    char pad[0x14];
    gfModelAnimation* anim;
};

struct Obj {
    char pad[0x88];
    int state;
    char pad2[0x10];
    Inner* inner;
};

extern "C" void fn_800F7454(Obj* self) {
    double f = fn_800F5344();
    if (self->state == 2) {
        int frame = (int)getFrame__16gfModelAnimationFd(self->inner->anim, f);
        if (frame == 0x66) {
            g_sndSystem->playSE((SndID)0x18F6, -1, 0, 0, 0x25);
        } else if (frame == 0x91) {
            g_sndSystem->playSE((SndID)0x18F7, -1, 0, 0, 0x25);
        }
    } else if (self->state == 6) {
        if ((int)getFrame__16gfModelAnimationFd(self->inner->anim, f) == 0x28) {
            g_sndSystem->playSE((SndID)0x18F8, -1, 0, 0, 0x25);
        }
    }
}
