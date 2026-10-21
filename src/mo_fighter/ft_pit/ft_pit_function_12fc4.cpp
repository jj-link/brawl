#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_112_12FC4(void*, soModuleAccesser* accesser) {
    accesser->getPostureModule().initRot();
    Vec3f pos = accesser->getPostureModule().getPos();
    pos.m_z = accesser->getGroundModule().getZ();
    accesser->getPostureModule().setPos(&pos);
}
