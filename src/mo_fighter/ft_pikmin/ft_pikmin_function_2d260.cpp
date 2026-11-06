#include <so/so_module_accesser.h>
#pragma force_active on

struct PikminModelPostureOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_113_2D374(Vec3f* dst, const Vec3f* src);

extern "C" void fn_113_2D260(PikminModelPostureOwner* object) {
    soModuleAccesser* accesser = object->accesser;
    float s = accesser->getPostureModule().getScale();
    Vec3f scale;
    scale.m_z = s;
    scale.m_y = s;
    scale.m_x = s;
    Vec3f rotation;
    Vec3f position;
    Vec3f rawPosition = accesser->getPostureModule().getPos();
    fn_113_2D374(&position, &rawPosition);
    Vec3f rawRotation = accesser->getPostureModule().getRot(0);
    fn_113_2D374(&rotation, &rawRotation);
    rotation.m_y += accesser->getPostureModule().getRotYLr();
    accesser->getModelModule().setNodeSRT(1, &scale, &rotation, &position);
    accesser->getModelModule().setNodeSRT(0, &scale, &rotation, &position);
}
