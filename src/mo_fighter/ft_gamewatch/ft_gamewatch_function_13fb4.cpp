#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" unsigned int fn_107_13FB4(void*, soModuleAccesser* accesser, Vec3f*) {
    Vec3f point = accesser->getModelModule().getNodeGlobalPosition(14, false);
    int areaId;
    return accesser->getAreaModule().getEnviromentElementChecker()->testWater(
        reinterpret_cast<Vec2f*>(&point), &areaId);
}
