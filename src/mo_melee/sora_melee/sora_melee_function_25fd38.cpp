#pragma force_active on

#include <gf/gf_model.h>

extern "C" float getFrame__16gfModelAnimationFd(gfModelAnimation*);
extern float lbl_27_rodata_42A4;

struct Ground {
    char m_pad[0x48];
    gfModelAnimation** m_motionAnims;
};

inline float motionFrame(gfModelAnimation* anim) {
    if (anim == 0) {
        return lbl_27_rodata_42A4;
    }
    return getFrame__16gfModelAnimationFd(anim);
}

extern "C" float getMotionFrame__6GroundFUl(Ground* self, unsigned long index) {
    return motionFrame(self->m_motionAnims[index]);
}
