#include <so/so_module_accesser.h>
#pragma force_active on

struct ZeldaModuleOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_104_1E33C(Vec3f* dst, const Vec3f* src);
extern "C" void fn_27_492C(void* object);

extern "C" void fn_104_241F4(ZeldaModuleOwner* object) {
    soModuleAccesser* accesser = object->accesser;
    if (accesser->getLinkModule().isLink(3) &&
        accesser->getWorkManageModule().isFlag(0x12000003)) {
        float scale = accesser->getPostureModule().getScale();
        Vec3f nodeScale;
        nodeScale.m_x = nodeScale.m_y = nodeScale.m_z = scale;
        Vec3f rotation;
        Vec3f position;
        u32 zero = 0;
        Vec3f rawPosition = accesser->getLinkModule().getParentModelNodeGlobalPosition(3, zero, false);
        fn_104_1E33C(&position, &rawPosition);
        Vec3f rawRotation = accesser->getLinkModule().getParentRot(3);
        fn_104_1E33C(&rotation, &rawRotation);
        rotation.m_y += accesser->getPostureModule().getRotYLr();
        accesser->getModelModule().setNodeSRT(0, &nodeScale, &rotation, &position);
    } else {
        fn_27_492C(object);
    }
}
