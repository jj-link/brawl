#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_115_rodata_C0;
extern const float lbl_115_rodata_D4;
}

extern "C" void fn_115_12E60(void*, soModuleAccesser* accesser) {
    Vec3f pos1 = accesser->getModelModule().getNodeRotate(4);
    pos1.m_x = accesser->getWorkManageModule().getFloat(0x21000005);
    accesser->getModelModule().setNodeRotate(4, &pos1);
    Vec3f pos2 = accesser->getModelModule().getNodeRotate(5);
    pos2.m_y = accesser->getWorkManageModule().getFloat(0x21000006);
    if (accesser->getStatusModule().getStatusKind() == 0x12c || accesser->getStatusModule().getStatusKind() == 0x12d) {
        if (lbl_115_rodata_C0 == accesser->getPostureModule().getLr()) {
            pos2.m_y = pos2.m_y + lbl_115_rodata_D4;
        }
    }
    accesser->getModelModule().setNodeRotate(5, &pos2);
}
