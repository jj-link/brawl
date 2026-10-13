#include <so/so_module_accesser.h>

extern "C" {
void fn_117_117D4(void*, soModuleAccesser*);
extern const float lbl_117_rodata_90, lbl_117_rodata_94;
}

extern "C" void fn_117_114AC(void* process, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116:
        break;
    case 0x138: {
        if (accesser->getPostureModule().getLr() == lbl_117_rodata_90) {
            Vec3f rotation = accesser->getModelModule().getNodeRotate(7);
            float z = rotation.m_z;
            Vec3f adjusted;
            adjusted.m_x = rotation.m_x;
            adjusted.m_y = lbl_117_rodata_94;
            adjusted.m_z = z;
            accesser->getModelModule().setNodeRotate(7, &adjusted);
        }
        if (accesser->getWorkManageModule().isFlag(0x22000011)) {
            fn_117_117D4(process, accesser);
        }
        break;
    }
    }
}
