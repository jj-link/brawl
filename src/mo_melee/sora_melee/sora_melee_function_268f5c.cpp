#include <gr/gr_yakumono_punch_slider.h>
#pragma force_active on

extern "C" void getPos__9grGimmickFv(Vec3f* out, void* self);
extern "C" void getRot__9grGimmickFv(Vec3f* out, void* self);
extern "C" void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* pos);
extern "C" void setRot__9grGimmickFP5Vec3f(void* self, Vec3f* rot);

void grYakumonoPunchSlider::updateMove(float /*deltaFrame*/) {
    Vec3f pos2;
    Vec3f rot2;
    Vec3f pos;
    Vec3f rot;
    getPos__9grGimmickFv(&pos, m_sliderMotionPath);
    pos2 = pos;
    getRot__9grGimmickFv(&rot, m_sliderMotionPath);
    rot2 = rot;
    setPos__9grGimmickFP5Vec3f(this, &pos2);
    setRot__9grGimmickFP5Vec3f(this, &rot2);
}
