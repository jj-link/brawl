#include <so/so_module_accesser.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_96_rodata_54C, lbl_96_rodata_550;
}

extern "C" void fn_96_24218(void*, soModuleAccesser* accesser)
{
    soSituationModule& situation = accesser->getSituationModule();
    soGroundModule& ground = accesser->getGroundModule();
    soPostureModule& posture = accesser->getPostureModule();
    soWorkManageModule& work = accesser->getWorkManageModule();

    float angle;
    float oldAngle = work.getFloat(0x11000001);
    angle = oldAngle;

    if (situation.getKind() == 0 &&
        ground.isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        Vec2f normal =
            ground.getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0);
        float y = normal.m_y;
        float x = normal.m_x;
        angle = atan2(x, y);
        angle *= posture.getLr();
    }

    if (angle != oldAngle) {
        Vec3f rot;
        rot.m_x = lbl_96_rodata_54C * angle;
        rot.m_y = lbl_96_rodata_550;
        rot.m_z = lbl_96_rodata_550;
        posture.setRot(&rot, 0);
        work.setFloat(angle, 0x11000001);
    }
}
