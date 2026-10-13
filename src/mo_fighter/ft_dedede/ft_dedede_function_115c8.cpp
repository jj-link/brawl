#include <so/so_module_accesser.h>

extern "C" {
extern const float lbl_117_rodata_90, lbl_117_rodata_94;
}

extern "C" void fn_117_115C8(void*, soModuleAccesser* accesser) {
    if (accesser->getStatusModule().getStatusKind() == 0x138) {
        if (accesser->getPostureModule().getLr() == lbl_117_rodata_90) {
            Vec3f rotation = accesser->getModelModule().getNodeRotate(7);
            float z = rotation.m_z;
            Vec3f adjusted;
            adjusted.m_x = rotation.m_x;
            adjusted.m_y = lbl_117_rodata_94;
            adjusted.m_z = z;
            accesser->getModelModule().setNodeRotate(7, &adjusted);
        }
    }
}
