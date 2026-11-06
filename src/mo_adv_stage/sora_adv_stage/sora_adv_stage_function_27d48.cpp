#include <gr/gr_gimmick_motion_path.h>
#include <gr/gr_yakumono.h>
#pragma force_active on

struct Self {
    char pad[0xcc];
    grGimmickMotionPath* path;
    char pad2[0x84];
    u32 effect;
    grGimmickMotionPathData* data;
};

extern "C" void fn_40_27D48(Self* self, float delta) {
    grGimmick* gimmick = (grGimmick*)self;
    gimmick->grGimmick::update(delta);
    if (self->effect) {
        ecMgr* mgr = g_ecMgr;
        Vec3f pos = gimmick->getPos();
        mgr->setPos(self->effect, &pos);
        ecMgr* mgr2 = g_ecMgr;
        Vec3f rot = gimmick->getRot();
        mgr2->setRot(self->effect, &rot);
    }
    if (!self->path->isMoveEnd() && *((u8*)self->data + 5) == 1) {
        if (self->path->isStartFrame())
            ((grYakumono*)self)->setValid(1);
        if (self->path->isEndFrame())
            ((grYakumono*)self)->setValid(0);
    }
    gimmick->grGimmick::updateCallback(0);
}