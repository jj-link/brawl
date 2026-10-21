#include <so/so_module_accesser.h>
#pragma force_active on

extern float lbl_27_rodata_22F4;
extern float lbl_27_rodata_22F8;

extern "C" void fn_27_176C68(void*, soModuleAccesser* moduleAccesser, float target, int interpolate) {
    Vec3f pos = moduleAccesser->m_enumerationStart->m_postureModule->getPos();
    if (interpolate == 0) {
        pos.m_x = target;
    } else {
        soMotionModule* motion = moduleAccesser->m_enumerationStart->m_motionModule;
        float endFrame = motion->getEndFrame();
        float factor = lbl_27_rodata_22F4 + lbl_27_rodata_22F8 * (motion->getFrame() / endFrame);
        pos.m_x += factor * (target - pos.m_x);
    }
    moduleAccesser->m_enumerationStart->m_postureModule->setPos(&pos);
}
