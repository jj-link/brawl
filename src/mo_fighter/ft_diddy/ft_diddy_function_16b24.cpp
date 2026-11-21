#include <so/so_module_accesser.h>
#pragma force_active on

struct DiddyObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_115_16B24(DiddyObject* object, Vec3f* position,
                            const Vec2f* speed, float facing, float scale, int flag) {
    object->accesser->getPostureModule().init(position, facing);
    object->accesser->getLinkModule().removeModelConstraint(true);
    object->accesser->getWorkManageModule().setFloat(scale, 0x21000000);
    if (flag != 0) {
        object->accesser->getStatusModule().changeStatusForce(2, object->accesser);
    } else {
        object->accesser->getWorkManageModule().setFloat(speed->m_x, 0x21000004);
        object->accesser->getWorkManageModule().setFloat(speed->m_y, 0x21000005);
        object->accesser->getStatusModule().changeStatusForce(1, object->accesser);
    }
}