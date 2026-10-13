#include <so/so_module_accesser.h>

extern "C" const float lbl_117_rodata_28[3];

extern "C" void fn_117_ED04(void*, soModuleAccesser* accesser) {
    if (lbl_117_rodata_28[1] == accesser->getPostureModule().getLr()) {
        Vec3f source = accesser->m_enumerationStart->m_modelModule->getNodeRotate(7);
        Vec3f rotation;
        float z = source.m_z;
        rotation.m_x = source.m_x;
        rotation.m_y = lbl_117_rodata_28[2];
        rotation.m_z = z;
        accesser->getModelModule().setNodeRotate(7, &rotation);
    }
}
