#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
#pragma always_inline on

extern "C" void fn_109_11DA0(void*, soModuleAccesser* accesser) {
    soPostureModule& posture = *accesser->m_enumerationStart->m_postureModule;
    Vec3f tmp = posture.getPos();
    Vec3f position;
    position.m_x = tmp.m_x;
    position.m_y = tmp.m_y;
    position.m_z = tmp.m_z;
    float lr = posture.getLr();
    float c = soValueAccesser::getConstantFloat(accesser, 0xfa2, 0);
    position.m_x = position.m_x + c * lr;
    posture.setPos(&position);
}
