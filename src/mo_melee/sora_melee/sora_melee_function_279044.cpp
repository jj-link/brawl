#pragma force_active on

#include <gr/gr_madein.h>
#include <ut/ut_nw.h>

extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
extern "C" const float lbl_27_rodata_4520;

void grMadein::endEntity() {
    gfModelAnimation* animation = m_modelAnims[0];
    if (animation != 0) {
        setFrame__16gfModelAnimationFd(animation, lbl_27_rodata_4520);
    }

    m_alive = false;

    setVisibility(0);

    if (((*(u8*)((char*)this + 0x16C) >> 6) & 1) != 0) {
        disableAttack(0);
    }

    if (((*(u8*)((char*)this + 0x16C) >> 5) & 1) != 0) {
        disableHit(0, 0);
    }

    unlink();

    gfTask* task = *(gfTask**)((char*)this + 0x14C);
    if (task != 0) {
        task->unlink();
    }

    nw4r::g3d::ScnMdlSimple* model = m_sceneModels[0];
    if (model != 0) {
        nwSMSetVisibility(model, false);
        model->SetScnObjOption(1, 1);
        model->SetScnObjOption(2, 1);
        model->SetScnObjOption(3, 1);
        model->SetScnObjOption(4, 1);
        model->SetScnObjOption(5, 1);
        model->SetScnObjOption(6, 1);
        model->SetScnObjOption(7, 1);
        model->SetScnObjOption(8, 1);
        model->SetScnObjOption(9, 0);
    }
}
