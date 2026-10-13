#include <so/so_module_accesser.h>

extern "C" {
extern const float lbl_117_rodata_48;
extern const float lbl_117_rodata_4C;
}

extern "C" void fn_117_F2D8(void*, soModuleAccesser* accesser) {
    if (lbl_117_rodata_48 == accesser->getPostureModule().getLr()) {
        Vec3f rotation = accesser->m_enumerationStart->m_modelModule->getNodeRotate(5);
        rotation.m_y = lbl_117_rodata_4C;
        accesser->getModelModule().setNodeRotate(5, &rotation);
    }
}
