#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_110_rodata_170;

extern "C" void fn_110_1901C(void* unused, soModuleAccesser* accesser) {
    Vec3f rot;
    soWorkManageModule& work = accesser->getWorkManageModule();
    soPostureModule& posture = accesser->getPostureModule();
    rot.m_x = -work.getFloat(0x21000000);
    rot.m_y = lbl_110_rodata_170;
    rot.m_z = lbl_110_rodata_170;
    posture.setRot(&rot, 0);
}
