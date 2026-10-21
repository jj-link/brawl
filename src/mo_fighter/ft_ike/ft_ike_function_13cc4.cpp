#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_119_13CC4(void*, soModuleAccesser* accesser) {
    Vec3f rotation = accesser->getModelModule().getNodeRotate(3);
    rotation.m_x = accesser->getWorkManageModule().getFloat(0x21000007);
    accesser->getModelModule().setNodeRotate(3, &rotation);
}
