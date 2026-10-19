#include <so/so_module_accesser.h>
#pragma force_active on

struct PokeModuleOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_116_10A30(Vec3f* dst, const Vec3f* src);
extern "C" void fn_27_492C(void* object);

extern "C" void fn_116_10E1C(PokeModuleOwner* object) {
    if (object->accesser->getStatusModule().getStatusKind() == 3) {
        float scale = object->accesser->getPostureModule().getScale();
        Vec3f nodeScale;
        nodeScale.m_x = nodeScale.m_y = nodeScale.m_z = scale;
        Vec3f rotation;
        Vec3f rotation2;
        Vec3f position;
        Vec3f rawPosition = object->accesser->getPostureModule().getPos();
        fn_116_10A30(&position, &rawPosition);
        Vec3f rawRotation = object->accesser->getPostureModule().getRot(0);
        fn_116_10A30(&rotation, &rawRotation);
        object->accesser->getModelModule().setNodeSRT(0, &nodeScale, &rotation, &position);
        Vec3f rawRotation2 = object->accesser->getPostureModule().getRot(1);
        fn_116_10A30(&rotation2, &rawRotation2);
        rotation2.m_x += object->accesser->getWorkManageModule().getFloat(0x11000001);
        object->accesser->getModelModule().setNodeRotate(2, &rotation2);
    } else {
        fn_27_492C(object);
    }
}
