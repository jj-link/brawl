#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on

extern "C" void fn_27_16A330(void*, soModuleAccesser* moduleAccesser, u32 arg) {
    if (arg == 1) {
        soControllerModule* controller = moduleAccesser->m_enumerationStart->m_controllerModule;
        float stick = controller->getStickX();
        float absStick = (float)(double)nw4r::math::FAbs(stick);
        float limit = soValueAccesser::getConstantFloat(moduleAccesser, 0xc65, 0);
        if (absStick >= limit) {
            Vec3f pos = moduleAccesser->m_enumerationStart->m_postureModule->getPos();
            float work = moduleAccesser->m_enumerationStart->m_workManageModule->getFloat(0x21000006);
            float scale = soValueAccesser::getConstantFloat(moduleAccesser, 0xc67, 0);
            float t = stick * scale;
            pos.m_x += t * work;
            moduleAccesser->m_enumerationStart->m_postureModule->setPos(&pos);
        }
    }
}
