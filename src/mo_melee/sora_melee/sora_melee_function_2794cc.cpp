#include <gr/gr_madein.h>
#include <gf/gf_model.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_4520;
extern "C" float getFrame__16gfModelAnimationFd(gfModelAnimation*);

float grMadein::getEntityFrame() {
    gfModelAnimation* anim = **(gfModelAnimation***)((char*)this + 0x48);
    float result;
    if (anim == 0) {
        result = lbl_27_rodata_4520;
    } else {
        result = getFrame__16gfModelAnimationFd(anim);
    }
    return result;
}
