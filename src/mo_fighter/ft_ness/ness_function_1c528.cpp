#include <so/so_module_accesser.h>

struct NessModelPostureOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" Vec3f* fn_101_1C628(Vec3f*, const Vec3f*);

// Apply world posture to the model's root node, including facing rotation.
extern "C" void fn_101_1C528(NessModelPostureOwner* object) {
    float scale = object->accesser->getPostureModule().getScale();
    Vec3f nodeScale;
    nodeScale.m_x = nodeScale.m_y = nodeScale.m_z = scale;
    Vec3f rotation;
    Vec3f position;
    Vec3f rawPosition = object->accesser->getPostureModule().getPos();
    fn_101_1C628(&position, &rawPosition);
    Vec3f rawRotation = object->accesser->getPostureModule().getRot(0);
    fn_101_1C628(&rotation, &rawRotation);
    rotation.m_y += object->accesser->getPostureModule().getRotYLr();
    object->accesser->getModelModule().setNodeSRT(0, &nodeScale, &rotation, &position);
}
