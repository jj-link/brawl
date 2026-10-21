#include <so/so_module_accesser.h>
#pragma force_active on

extern const float lbl_107_rodata_C0;
extern const float lbl_107_rodata_C4;

extern "C" float fn_107_14030(void*, soModuleAccesser* accesser) {
    Vec3f point = accesser->getModelModule().getNodeGlobalPosition(14, false);
    int water;
    if (accesser->getAreaModule().getEnviromentElementChecker()->testWater(
            reinterpret_cast<Vec2f*>(&point), &water)) {
        Vec3f translation = accesser->getMotionModule().getTransNTranslate();
        return (*reinterpret_cast<float*>(&water) + translation.m_y) - lbl_107_rodata_C0;
    }
    return lbl_107_rodata_C4;
}
