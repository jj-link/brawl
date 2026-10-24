#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_91_rodata_98;
void fn_91_19184(void*, soModuleAccesser* accesser, unsigned int node, const Vec3f* target, Vec3f* origin);

void fn_91_192D0(void* arg0, soModuleAccesser* accesser) {
    Vec3f target;
    Vec3f origin;
    target.m_x = accesser->getWorkManageModule().getFloat(0x11000001);
    target.m_y = accesser->getWorkManageModule().getFloat(0x11000002);
    target.m_z = lbl_91_rodata_98;
    fn_91_19184(arg0, accesser, 3, &target, &origin);
    accesser->getWorkManageModule().setFloat(origin.m_x, 0x11000001);
    accesser->getWorkManageModule().setFloat(origin.m_y, 0x11000002);

    target.m_x = accesser->getWorkManageModule().getFloat(0x11000003);
    target.m_y = accesser->getWorkManageModule().getFloat(0x11000004);
    fn_91_19184(arg0, accesser, 4, &target, &origin);
    accesser->getWorkManageModule().setFloat(origin.m_x, 0x11000003);
    accesser->getWorkManageModule().setFloat(origin.m_y, 0x11000004);
}
}
