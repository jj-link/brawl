#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

#include <ft_metaknight/ft_metaknight_posture_constants.h>

extern "C" void fn_111_C710(void*, soModuleAccesser* accesser) {
    const MetaKnightPostureConstants& limits = lbl_111_rodata_10;
    if (limits.neutral != accesser->getControllerModule().getStickY()) {
        float stickY = accesser->getControllerModule().getStickY();
        if (stickY < limits.minimum) {
            stickY = limits.minimum;
        } else if (stickY > limits.maximum) {
            stickY = limits.maximum;
        }
        Vec3f rotation = accesser->m_enumerationStart->m_postureModule->getRot(0);
        rotation.m_x += -stickY * soValueAccesser::getConstantFloat(accesser, 0xFB4, 0);
        accesser->getPostureModule().setRot(&rotation, 0);
    }
}
