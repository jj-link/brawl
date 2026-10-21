#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_119_1391C(void*, soModuleAccesser* accesser) {
    switch (accesser->m_enumerationStart->m_statusModule->getStatusKind()) {
    case 3:
        Vec3f rotation = accesser->m_enumerationStart->m_modelModule->getNodeRotate(3);
        rotation.m_x = accesser->m_enumerationStart->m_workManageModule->getFloat(0x21000007);
        accesser->m_enumerationStart->m_modelModule->setNodeRotate(3, &rotation);
        break;
    }
}
