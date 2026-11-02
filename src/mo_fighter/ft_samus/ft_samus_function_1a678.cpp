#include <ft/ft_common_data_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/so_module_accesser.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on
extern "C" void fn_94_1A678(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* enumeration = accesser->m_enumerationStart;
    soWorkManageModule* work = enumeration->m_workManageModule;
    soControllerModule* controller = enumeration->m_controllerModule;
    soPostureModule* posture = enumeration->m_postureModule;
    char* data = *(char**)((char*)g_ftCommonDataAccesser.getData((ftKind)0x18) + 0x84);

    float lr = posture->getLr();
    float stick = controller->getStickX();
    if (nw4r::math::FAbs(stick) >= *(float*)(data + 0x10)) {
        float stickSign = (float)((stick < 0.0f) ? -1 : 1);
        float lrSign = (float)((lr < 0.0f) ? -1 : 1);
        if (lrSign == stickSign) {
            work->onFlag(0x2200001C);
        }
    }
    if (work->isFlag(0x2200001B)) {
        work->offFlag(0x2200001B);
        if (work->isFlag(0x2200001C)) {
            posture->reverseLr();
            posture->updateRotYLr();
        }
    }
}
