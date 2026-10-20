#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" const float lbl_110_rodata_168;
extern "C" void fn_110_18C04(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soPostureModule* posture = &accesser->getPostureModule();
    Vec3f rotation;
    rotation.m_x = -work->getFloat(0x21000000);
    rotation.m_y = lbl_110_rodata_168;
    rotation.m_z = lbl_110_rodata_168;
    posture->setRot(&rotation, 0);
}
