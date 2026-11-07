#include <gr/gr_gimmick.h>
#include <gf/gf_model.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_4328;
extern "C" u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);

extern "C" void fn_27_26A170(grGimmick* self, int arg) {
    *(u8*)*(void**)((char*)self + 0x150) = 1;
    gfModelAnimation** anims = *(gfModelAnimation***)((char*)self + 0x48);
    if (bool((*anims)->m_resFile.GetResAnmChrNumEntries()) == true) {
        self->grGimmick::changeNodeAnim(0, 0);
        if (arg == 0) {
            gfModelAnimation* anim = **(gfModelAnimation***)((char*)self + 0x48);
            setFrame__16gfModelAnimationFd(anim, (float)getFrameCount__16gfModelAnimationFd(anim));
        }
    }
    *(int*)((char*)self + 0x154) = 1;
    *(float*)((char*)self + 0x158) = lbl_27_rodata_4328;
    if (arg != 0) {
        self->startGimmickSE(0);
        self->startGimmickEffect(0);
    }
}