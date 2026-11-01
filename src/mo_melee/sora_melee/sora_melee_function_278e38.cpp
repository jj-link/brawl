#pragma force_active on

#include <types.h>
#include <gf/gf_model.h>
#include <gr/gr_madein.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <ut/ut_nw.h>

extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
extern "C" void fn_27_278720(grMadein*);
extern "C" const float lbl_27_rodata_4520;

void grMadein::startEntity() {
    gfModelAnimation* animation = *m_modelAnims;
    if (animation != 0) {
        setFrame__16gfModelAnimationFd(animation, lbl_27_rodata_4520);
        setLoop__16gfModelAnimationFd(animation, false);
    }

    ((u8*)this)[0x2C] |= 0x40;
    setVisibility(1);
    *(s32*)((char*)this + 0x1A0) = 0;
    fn_27_278720(this);

    if ((((u8*)this)[0x16C] >> 5) & 1) {
        enableHit(0, 0);
    }

    link(this != 0);

    gfTask* task = *(gfTask**)((char*)this + 0x14C);
    if (task != 0) {
        task->link(task != 0);
    }

    nw4r::g3d::ScnMdlSimple* model = *m_sceneModels;
    if (model != 0) {
        model->SetScnObjOption(1, *(u32*)((char*)this + 0x17C));

        if ((((u8*)this)[0x6D] >> 3) & 1) {
            model->SetScnObjOption(2, *(u32*)((char*)this + 0x180));
            model->SetScnObjOption(3, *(u32*)((char*)this + 0x184));
            model->SetScnObjOption(4, *(u32*)((char*)this + 0x188));
            model->SetScnObjOption(8, *(u32*)((char*)this + 0x198));
        }

        model->SetScnObjOption(5, *(u32*)((char*)this + 0x18C));
        model->SetScnObjOption(6, *(u32*)((char*)this + 0x190));
        model->SetScnObjOption(7, *(u32*)((char*)this + 0x194));
        model->SetScnObjOption(9, *(u32*)((char*)this + 0x19C));
        nwSMSetVisibility(model, true);
    }
}
