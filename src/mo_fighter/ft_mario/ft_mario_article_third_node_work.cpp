#include <so/so_module_accesser.h>

extern "C" void fn_91_19088(void*, soModuleAccesser* accesser) {
    Vec3f first = accesser->getModelModule().getNodeGlobalPosition(3, false);
    accesser->getWorkManageModule().setFloat(first.m_x, 0x11000001);
    accesser->getWorkManageModule().setFloat(first.m_y, 0x11000002);
    Vec3f second = accesser->getModelModule().getNodeGlobalPosition(4, false);
    accesser->getWorkManageModule().setFloat(second.m_x, 0x11000003);
    accesser->getWorkManageModule().setFloat(second.m_y, 0x11000004);
}
