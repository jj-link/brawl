#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_96_28AA4(void*, soModuleAccesser* accesser) {
    Vec3f rotation = accesser->getModelModule().getNodeRotate(1);
    rotation.m_x = accesser->getWorkManageModule().getFloat(0x21000002);
    accesser->getModelModule().setNodeRotate(1, &rotation);
}
