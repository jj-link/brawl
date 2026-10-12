#include <so/so_module_accesser.h>
#include <math.h>

struct PikachuRootTransformOwner {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

extern "C" {
extern const float lbl_98_rodata_A0, lbl_98_rodata_A8;
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
void fn_98_144E8(soModuleAccesser*, unsigned int, int);
#pragma section data_type ".data$pikachu14328" ".bss"
float lbl_98_data_7BE0 = 40.0f;
#pragma section data_type ".data" ".bss"
}

// Stretch the root along Y by the stored endpoint distance, then update its effects.
static inline void updateRootTransform(soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    float first = work->getFloat(0x11000001);
    double absoluteDistance = fabs(first - work->getFloat(0x11000002));
    float distance = absoluteDistance;
    float scaleY = work->getFloat(0x11000004);
    Vec3f scale;
    Vec3f rotation;
    Vec3f position = accesser->getPostureModule().getPos();
    fn_98_F5B0(&rotation, lbl_98_rodata_A8, lbl_98_rodata_A8, lbl_98_rodata_A8);
    fn_98_F5B0(&scale, lbl_98_rodata_A0, lbl_98_rodata_A0, lbl_98_rodata_A0);
    scale.m_y = scaleY * (distance / lbl_98_data_7BE0);
    accesser->getModelModule().setNodeSRT(0, &scale, &rotation, &position);
    fn_98_144E8(accesser, 0x1000000A, 0);
    fn_98_144E8(accesser, 0x1000000B, 2);
}

extern "C" void fn_98_14328(PikachuRootTransformOwner* owner) {
    updateRootTransform(owner->accesser);
}
