#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_117_rodata_38;
extern const float lbl_117_rodata_3C;
}

extern "C" void fn_117_EF20(void*, soModuleAccesser* accesser) {
    if (lbl_117_rodata_38 == accesser->getPostureModule().getLr()) {
        Vec3f rotation = accesser->getModelModule().getNodeRotate(6);
        rotation.m_y = lbl_117_rodata_3C;
        accesser->getModelModule().setNodeRotate(6, &rotation);
    }
}
